/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:25:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/23 22:58:41 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_print_ray(t_player *p, int ex)
{
	int i;
	int texture_y;
	int texture_x;
	int pixel;
	float wall_hit_position;
	uint32_t color;

	if (p->rc->side == 0) // Mur vertical (nord-sud)
		wall_hit_position = p->rc->x - floor(p->rc->x);
	else // Mur horizontal (est-ouest)
		wall_hit_position = p->rc->y - floor(p->rc->y);

	texture_x = (int)(wall_hit_position * p->game->north_texture->width);
	if (texture_x < 0)\
		texture_x = 0;
	if (texture_x >= p->game->north_texture->width)
		texture_x = p->game->north_texture->width - 1;

	i = 0;
	while (i < p->rc->drawStart)
	{
		mlx_put_pixel(p->game->image, ex, i, 0x0000B4FF); // Couleur du ciel
		i++;
	}
	while (i < p->rc->drawEnd)
	{
		// Calculer la position Y sur la texture en fonction de la hauteur du mur
		texture_y = (int)((i - p->rc->drawStart) * (p->game->north_texture->height / (float)(p->rc->drawEnd - p->rc->drawStart)));
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= p->game->north_texture->height)
			texture_y = p->game->north_texture->height - 1; //if point is too big or too small : resize to smaller point or bigger from the texture.

		//Because pixel is store in a ray9* and not a ray of ray (**), we do :
		//texture_y (wich is the y of pixel we want to put)
		// * the weight of texture : like 6 * 64 (and the result is the line we want)
		//AND we add texture x for being not at the start of the line, but in the correct x pos.
		//Put it on escalidraw or come see me (or discord) if explaination needed
		//so it gives us this line :
		pixel = texture_y * p->game->north_texture->width + texture_x;

		//verif if ok
		if (pixel < 0)
			pixel = 0;
		if (pixel >= p->game->north_texture->width * p->game->north_texture->height)
			pixel = p->game->north_texture->width * p->game->north_texture->height - 1;

		//and now that we have the index of the pixel in our ray, lets get the color of it :
		color = p->game->north_texture->pixels[pixel];

		// Afficher le pixel sur l'image finale
		mlx_put_pixel(p->game->image, ex, i, color);
		i++;
	}
	// Afficher le sol en dessous du mur
	while (i < p->game->height)
	{
		mlx_put_pixel(p->game->image, ex, i, 0x000000FF); // Couleur du sol
		i++;
	}
}





//define draw start and draw end, its were we should drow on the y line (vertical line)
static void	ft_define_print(t_player *p)
{
	p->rc->drawStart = - p->rc->wall_height / 2.0 + (float)p->game->height / 2.0;
	p->rc->drawEnd = p->rc->wall_height / 2.0 + (float)p->game->height / 2.0;
	if (p->rc->drawStart < 0)
		p->rc->drawStart = 0;
	if (p->rc->drawEnd >= p->game->height)
		p->rc->drawEnd = p->game->height - 1.0;
}

static void ft_calcul_wall(t_player *p)
{
	//calcul to remove fishy
	if(p->rc->side == 0)
		p->rc->perpWallDist = (p->rc->sideDistX - p->rc->deltaDistX);
	else
		p->rc->perpWallDist = (p->rc->sideDistY - p->rc->deltaDistY);
	//find wallheight
	p->rc->wall_height = (p->game->height / (p->rc->perpWallDist * cos(p->or - p->rc->angle))); // change
	p->rc->wall_height = floor(p->rc->wall_height * 10.0) / 10.0;
}

//know what side of the wall we'r talking
static void	ft_find_side(t_player *p, char map[7][11])
{
	while (p->rc->hit == 0)
	{
		if (p->rc->sideDistX < p->rc->sideDistY)
		{
			p->rc->sideDistX += p->rc->deltaDistX;
			p->rc->mapX += p->rc->stepX;
			p->rc->side = 0;
		}
		else
		{
			p->rc->sideDistY += p->rc->deltaDistY;
			p->rc->mapY += p->rc->stepY;
			p->rc->side = 1;
		}
		if (p->rc->mapY < 0 || p->rc->mapY >= 7 || p->rc->mapX < 0 || p->rc->mapX >= (int)ft_strlen(map[p->rc->mapY]))
			p->rc->hit = 1;
		if (map[p->rc->mapY][p->rc->mapX] == '1')
			p->rc->hit = 1;
	}
}

void	ft_ray_casting(void *param)
{
	//ex is like ecran x (horizontal value of pixel of the screen)

	t_player *p;
	int	ex;
	char map[7][11] = {"1111111111\0",
					"1000100011\0",
					"1000000001\0",
					"1000000001\0",
					"1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					"1111111111\0",
					""};

	p = (t_player *)param;
	ex = 0;
	while (ex < p->game->width)
	{
		//we redefine rc every frame, because it set var needed by ray casting
		ft_define_rc(p, ex);
		//know what side of the wall we'r talking
		ft_find_side(p, map);
		//calcul wall height and remove fishy
		ft_calcul_wall(p);
		//define draw start and draw end
		ft_define_print(p);
		//print ray, its here to change color :
		ft_print_ray(p, ex);
		ex++;
	}
}

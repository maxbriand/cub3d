/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:47:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/29 03:25:38 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static uint32_t	ft_define_color(t_player *p, int pixel)
{
	uint32_t	color;

	color = *(uint32_t*)(p->game->north_texture->pixels + pixel);
	//now the color is set to the R (red). we need now to add to him GBA, by increment the adress of pixel one by one :
	//pixel is a uint8_t, and color is a uint32_t. So we add 8 bites each time we whant to add a color
		//NOTE : color is like this : 00(RED) 00(GREEN) 00(BLUE) 00(transparence but idk in english)
		//so color is = to 00000000 in hexa, and you add here the color :
	color = (color << 8) + p->game->north_texture->pixels[pixel+ 1];
	color = (color << 8) + p->game->north_texture->pixels[pixel+ 2];
	color = (color << 8) + p->game->north_texture->pixels[pixel+ 3];
	//up here we move to 8 bites the bites of color to the letf, then we add the G, then we move again to 8, add B etc..
	//if not clear come see me or in discord (galadou)
	return (color);
}

// Calculer la position Y sur la texture en fonction de la hauteur du mur
static int	ft_define_ty(t_player *p, int sy)
{
	int	text_y;

	text_y = (int)((sy - p->rc->drawStart) * /*(float)*/p->game->north_texture->height / (p->rc->drawEnd - p->rc->drawStart));
	if (text_y < 0)
		text_y = 0;
	if (text_y >= p->game->north_texture->height)
		text_y = p->game->north_texture->height - 1; //if point is too big or too small : resize to smaller point or bigger from the texture.
	return (text_y);
}

//text_x is the coordinate of the wall we want to put texture
static int	ft_define_tx(t_player *p)
{
	int	text_x;

	text_x = (p->rc->wall_hit_position * (float)(p->game->north_texture->width - 1));
	if(p->rc->side == 0 && p->rc->rayDirX > 0.0)
		text_x = p->game->north_texture->width - text_x - 1;
	if(p->rc->side == 1 && p->rc->rayDirY < 0.0)
		text_x = p->game->north_texture->width - text_x - 1;

	//if (text_x < 0)
	//	text_x = 0;
	//if (text_x >= p->game->north_texture->width)
	//	text_x = p->game->north_texture->width - 1;
	return (text_x);
}

void	ft_print_ray(t_player *p, int sx)
{
	int			sy;
	int			text_y;
	int			text_x;
	int			pixel;
	uint32_t	color;

	color = 0xB400B4FF; //define color of the wall
	if (p->rc->side)
		color = (color / 2) | 0xFF;
	//TO REMOVE

	//text_x is the coordinate of the wall we want to put texture
	text_x = ft_define_tx(p);

	sy = 0;
	while (sy < p->rc->drawStart)
	{
		mlx_put_pixel(p->game->image, sx, sy, 0x0000B4FF); // Couleur du ciel
		sy++;
	}
	while (sy < p->rc->drawEnd)
	{
		// Calculer la position Y sur la texture en fonction de la hauteur du mur
		text_y = ft_define_ty(p, sy);

		//Because pixel is store in a char* and not a ray of ray (char**), we do :
		//text_y (wich is the y of pixel we want to put)
		// * the width of texture : like 6 * 64 (and the result is the line we want)
		//AND we add texture x for being not at the start of the line, but in the correct x pos.
		//Put it on escalidraw or come see me (or discord) if explaination needed
		//so it gives us this line :
		pixel = (p->game->north_texture->width * text_y + text_x) * 4;
		//pixel need to be multiplicate by 4, because pixel is a group of 4 pixel (R + G + B + A)

		//verif if undo 0
		//if (pixel < 0)
			//pixel = 0;

		//and now that we have the index of the pixel in our ray, lets get the color of it :

		//we define the color of the pixel we'r gonna print
		color = ft_define_color(p, pixel);


		//Add pixel to the image : (sx is screen x, sy is screen y)
		mlx_put_pixel(p->game->image, sx, sy, color);
		sy++;
	}
	// Afficher le sol en dessous du mur
	while (sy < p->game->height)
	{
		mlx_put_pixel(p->game->image, sx, sy, 0x000000FF / 2); // Couleur du sol
		sy++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:47:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/09 02:58:38 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static uint32_t ft_define_color(t_player *p, uint32_t color)
{
	float		brightness;
	//p->rc->per

	//brightness = 1.1 * p->rc->distance_factor;
	//brightness = 1.0;
    // Extraire les composants de couleur
    uint8_t r = ((color >> 24) & 0xFF) * p->rc->distance_factor; // Alpha
    uint8_t g = ((color >> 16) & 0xFF) * p->rc->distance_factor; // Rouge
    uint8_t b = ((color >> 8) & 0xFF) * p->rc->distance_factor;  // Vert
    uint8_t a = color & 0xFF;         // Bleu

    return ((r << 24) | (g << 16) | (b << 8) | a);

}

static void	ft_put_floor_wall(t_player *p, int text_y, int text_x, int s[2])
{
	uint32_t	color;
	int			pixel;
		// Calculer la position Y sur la texture en fonction de la hauteur du mur
		//text_y = ft_define_ty(p, s[0]);
		//text_y = p->game->text->height / (p->rc->drawEnd - p->rc->drawStart);
		//pixel = (p->game->text->width * text_y + text_x); // remove *4

	if (p->rc->perpWallDist != p->rc->last_pwd) //erreur par ici
	{
		p->rc->last_pwd = p->rc->perpWallDist;
		p->rc->distance_factor =  1.0 / (p->rc->perpWallDist + 1.0) ;
	}
	while (s[0] < p->rc->drawEnd && s[0] != p->game->height - 1)
	{

		text_y = (int)((s[0] - p->rc->drawStart) * (float)p->game->text->height / (p->rc->drawEnd - p->rc->drawStart));
		pixel = (p->game->text->width * text_y + text_x); // remove *4


		//Because pixel is store in a char* and not a ray of ray (char**), we do :
		//text_y (wich is the y of pixel we want to put)
		// * the width of texture : like 6 * 64 (and the result is the line we want)
		//AND we add texture x for being not at the start of the line, but in the correct x pos.
		//Put it on escalidraw or come see me (or discord) if explaination needed
		//so it gives us this line :
		//pixel = (p->game->text->width * text_y + text_x); // remove *4

		//here
		//pixel need to be multiplicate by 4, because pixel is a group of 4 pixel (R + G + B + A)

		//verif if undo 0
		if (pixel < 0)
			pixel = 0;

		//and now that we have the index of the pixel in our ray, lets get the color of it :
		//we define the color of the pixel we'r gonna print
		//color = ft_define_color(p, pixel);
		//color = 0x0000FFFF;
		//mlx_put_pixel(p->game->image, s[1], s[0], p->game->color_ray_text[pixel]);
		if (s[0] > 0  && s[0] < p->game->height && s[1] > 0 && s[1] < p->game->width)
			mlx_put_pixel(p->game->image, s[1], s[0], ft_define_color(p, p->game->color_ray_text[pixel]));
			//mlx_put_pixel(p->game->image, s[1], s[0], color);


		// if (p->game->text == p->data->map.t_no_path)
		// 	mlx_put_pixel(p->game->image, s[1], s[0], ft_define_color(p, p->game->color_north[pixel]));
		// else if (p->game->text == p->data->map.t_so_path)
		// 	mlx_put_pixel(p->game->image, s[1], s[0], ft_define_color(p, p->game->color_south[pixel]));
		// else if (p->game->text == p->data->map.t_we_path)
		// 	mlx_put_pixel(p->game->image, s[1], s[0], ft_define_color(p, p->game->color_west[pixel]));
		// else if (p->game->text == p->data->map.t_ea_path)
		// 	mlx_put_pixel(p->game->image, s[1], s[0], ft_define_color(p, p->game->color_east[pixel]));

		s[0]++;
	}
	// Afficher le sol en dessous du mur
	color = p->data->map.floor_r;
	color = (color << 8) + p->data->map.floor_g;
	color = (color << 8) + p->data->map.floor_b;
	color = (color << 8) + 0xFF;
	while (s[0] < p->game->height)
	{
		mlx_put_pixel(p->game->image, s[1], s[0], color); // Couleur du sol
		s[0]++;
	}
}

void	ft_print_ray(t_player *p, int sx)
{
	int			s[2];
	int			text_y;
	int			text_x;
	uint32_t	color;

	text_x = (p->rc->wall_hit_position * (float)(p->game->text->width - 1));


	s[0] = 0; //y
	s[1] = sx; //x
	color = p->data->map.ceil_r;
	color = (color << 8) + p->data->map.ceil_g;
	color = (color << 8) + p->data->map.ceil_b;
	color = (color << 8) + 0xFF;
	while (s[0] < p->rc->drawStart)
	{
		mlx_put_pixel(p->game->image, s[1], s[0], color); // Couleur du ciel
		s[0]++;
	}
	ft_put_floor_wall(p, text_y, text_x, s);
}

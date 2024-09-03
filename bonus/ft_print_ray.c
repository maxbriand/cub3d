/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:47:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/03 16:56:39 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//GOOOOD
static uint32_t	ft_define_color(t_player *p, int pixel)
{
	uint32_t	color;
	float		distance_factor;
	uint8_t		*pixels;
	float		brightness;

	pixels = p->game->text->pixels;
	// distance factor is if more loin = more sombre
	//if (sx > screen_center_x / 2 && sx < screen_center_x + screen_center_x / 2
		//&& sy > screen_center_y / 2 && sy < screen_center_y + screen_center_y / 2)
	distance_factor = p->rc->distance_factor;
	brightness = p->game->brightness * distance_factor;
		//else
	//	distance_factor = 1.0;
	//add factor britness to color
	color = ((uint8_t)(pixels[pixel] * brightness) << 24) |  // Rouge
		((uint8_t)(pixels[pixel + 1] * brightness) << 16) |  // Vert
		((uint8_t)(pixels[pixel + 2] * brightness) << 8)  |  // Bleu
		(pixels[pixel + 3]); 

	// final color

	return (color);
}

// Calculer la position Y sur la texture en fonction de la hauteur du mur
static int	ft_define_ty(t_player *p, int sy)
{
	int	text_y;

	text_y = (int)((sy - p->rc->drawStart) * /*(float)*/p->game->text->height / (p->rc->drawEnd - p->rc->drawStart));
	//if (text_y < 0)
	//	text_y = 0;

	//secure
	//if (text_y >= p->game->text->height)
	//	text_y = p->game->text->height - 1; //if point is too big or too small : resize to smaller point or bigger from the texture.
	return (text_y);
}

//text_x is the coordinate of the wall we want to put texture
static int	ft_define_tx(t_player *p)
{
	int	text_x;


	text_x = (p->rc->wall_hit_position * (float)(p->game->text->width - 1));

	//if(p->rc->side == 0 && p->rc->rayDirX > 0.0)
	//	text_x = p->game->text->width - text_x - 1;
	//if(p->rc->side == 1 && p->rc->rayDirY < 0.0)
	//	text_x = p->game->text->width - text_x - 1;
	//if (text_x < 0)
	//	text_x = 0;
	//if (text_x >= p->game->north_texture->width)
	//	text_x = p->game->north_texture->width - 1;
	return (text_x);
}

static void	ft_put_floor_wall(t_player *p, int text_y, int text_x, int *s)
{
	uint32_t	color;
	int			pixel;

	while (s[0] < p->rc->drawEnd && s[0] != p->game->height - 1)
	{
		if (p->rc->perpWallDist != p->rc->last_pwd) //erreur par ici
		{
			p->rc->last_pwd = p->rc->perpWallDist;
			p->rc->distance_factor =  1.0 / (p->rc->perpWallDist + 1.0);
		}

		
		// Calculer la position Y sur la texture en fonction de la hauteur du mur
		text_y = ft_define_ty(p, s[0]);

		//Because pixel is store in a char* and not a ray of ray (char**), we do :
		//text_y (wich is the y of pixel we want to put)
		// * the width of texture : like 6 * 64 (and the result is the line we want)
		//AND we add texture x for being not at the start of the line, but in the correct x pos.
		//Put it on escalidraw or come see me (or discord) if explaination needed
		//so it gives us this line :
		pixel = (p->game->text->width * text_y + text_x) * 4;
		//here
		//pixel need to be multiplicate by 4, because pixel is a group of 4 pixel (R + G + B + A)

		//verif if undo 0
		//if (pixel < 0)
			//pixel = 0;

		//and now that we have the index of the pixel in our ray, lets get the color of it :
		//we define the color of the pixel we'r gonna print
		color = ft_define_color(p, pixel);
		//color = 0x0000FFFF;

		//Add pixel to the image : (sx is screen x, sy is screen y)
		mlx_put_pixel(p->game->image, s[1], s[0], color);
		s[0]++;
	}
	// Afficher le sol en dessous du mur
	while (s[0] < p->game->height)
	{
		color = p->data->map.floor_r;
		color = (color << 8) + p->data->map.floor_g;
		color = (color << 8) + p->data->map.floor_b;
		color = (color << 8) + 0xFF;
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

	//color = 0xB400B4FF; //define color of the wall
	//if (p->rc->side)
	//	color = (color / 2) | 0xFF;
	//TO REMOVE

	//text_x is the coordinate of the wall we want to put texture
	text_x = ft_define_tx(p);

	s[0] = 0; //y
	s[1] = sx; //x
	while (s[0] < p->rc->drawStart)
	{
		color = p->data->map.ceil_r;
		color = (color << 8) + p->data->map.ceil_g;
		color = (color << 8) + p->data->map.ceil_b;
		color = (color << 8) + 0xFF;


		mlx_put_pixel(p->game->image, s[1], s[0], color); // Couleur du ciel
		s[0]++;
	}
	ft_put_floor_wall(p, text_y, text_x, s);
}

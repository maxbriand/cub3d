/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:47:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/02 20:59:44 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// static uint32_t	ft_define_color(t_player *p, int pixel, int sx, int sy)
// {
// 	uint32_t	color;

// 			//color = (uint8_t)(p->game->text->pixels[pixel] + p->game->brightness);
// 		color = (uint8_t)(p->game->text->pixels[pixel]);
// 		//now the color is set to the R (red). we need now to add to him GBA, by increment the adress of pixel one by one :
// 		//pixel is a uint8_t, and color is a uint32_t. So we add 8 bites each time we whant to add a color
// 			//NOTE : color is like this : 00(RED) 00(GREEN) 00(BLUE) 00(transparence but idk in english)
// 			//so color is = to 00000000 in hexa, and you add here the color :
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel+ 1]);
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel+ 2]);
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel+ 3]);
// 		//up here we move to 8 bites the bites of color to the letf, then we add the G, then we move again to 8, add B etc..
// 		//if not clear come see me or in discord (galadou)
// 	return (color);
// }


		//INTERRESSANT
// static uint32_t	ft_define_color(t_player *p, int pixel, int sx, int sy)
// {
// 	uint32_t	color = 0;
// 	int			screen_center_x;
// 	int			screen_center_y;
// 	float		distance_factor;
// 	float		distance_to_center;
// 	float		halo_intensity = 1.5;  // Ajuster pour l'intensité du halo
// 	float		halo_radius = p->game->width / 4.0;  // Rayon du halo
// 	float		brightness;

// 	//printf("%f \n", p->rc->perpWallDist);
// 	distance_factor = 1.0 / (p->rc->perpWallDist + 1.0);
// 	screen_center_x = p->game->width / 2;
// 	screen_center_y = p->game->height / 2;

// 	// Calculer la distance au centre de l'écran
// 	distance_to_center = sqrtf((sx - screen_center_x) * (sx - screen_center_x) +
// 	                           (sy - screen_center_y) * (sy - screen_center_y));


// 		brightness = p->game->brightness * distance_factor;
// 		if (brightness > 2.0)  // Ajustez cette limite pour éviter une luminosité excessive
// 			brightness = 2.0;

// 	// Vérifier si le pixel est dans la zone du halo
// 	if (distance_to_center <= halo_radius)
// 	{
// 		// Calculer l'intensité du halo basée sur la distance au centre
// 		float halo_effect = 10.0 - (distance_to_center / halo_radius);
// 		if (halo_effect < 0.0)
// 			halo_effect = 0.0;

// 		brightness += 0.1;
// 		if (brightness > 1.5)  // Ajustez cette limite pour éviter une luminosité excessive
// 			brightness = 1.5;

// 		// Calculer la couleur avec effet de halo
// 		color = (uint8_t)(p->game->text->pixels[pixel] * halo_effect * distance_factor * brightness);
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 1] * halo_effect * distance_factor * brightness);
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 2] * halo_effect * distance_factor * brightness);
// 		color = (color << 8) + (uint8_t)p->game->text->pixels[pixel + 3];  // Alpha
// 	}
// 	else
// 	{
// 		float halo_effect = 5.0 - (distance_to_center / halo_radius);
// 		if (halo_effect < 0.0)
// 			halo_effect = 0.0;
// 		// Appliquer une couleur sombre (noir) pour les pixels en dehors de la zone du halo
// 		color = 0x000000FF;  // Noir avec alpha 255 (opaque)
// 		color = (uint8_t)(p->game->text->pixels[pixel] * halo_effect * distance_factor * brightness);
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 1] * halo_effect * distance_factor * brightness);
// 		color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 2] * halo_effect * distance_factor * brightness);
// 		color = (color << 8) + (uint8_t)p->game->text->pixels[pixel + 3];  // Alpha
// 	}

// 	return color;
// }




static uint32_t	ft_define_color(t_player *p, int pixel)
{
	uint32_t	color;
	float		distance_factor;
	uint8_t		red, green, blue, alpha;

	// distance factor is if more loin = more sombre
	distance_factor = 1.0 / (p->rc->perpWallDist + 1.0); // more close= more brightness

	//add factor britness to color
	red = (uint8_t)(p->game->text->pixels[pixel] * distance_factor * p->game->brightness);
	green = (uint8_t)(p->game->text->pixels[pixel + 1] * distance_factor * p->game->brightness);
	blue = (uint8_t)(p->game->text->pixels[pixel + 2] * distance_factor * p->game->brightness);
	alpha = (uint8_t)(p->game->text->pixels[pixel + 3]);

	// final color
	color = (red << 24) + (green << 16) + (blue << 8) + alpha;

	return (color);
}



// static uint32_t	ft_define_color(t_player *p, int pixel, int sx, int sy)
// {
// 	uint32_t	color;
// 	float		distance_factor;
// 	float		brightness;
// 	float		halo_factor;
// 	int			screen_center_x;
// 	int			screen_center_y;
// 	float		distance_to_center;
// 	float		halo_intensity = 10.5;  // Constante pour ajuster l'intensité du halo
// 	float		halo_radius = p->game->width / 4.0f;  // Rayon du halo

// 	// Déterminer le centre de l'écran
// 	screen_center_x = p->game->width / 2;
// 	screen_center_y = p->game->height / 2;

// 	// Calculer la distance au centre de l'écran
// 	distance_to_center = sqrtf((sx - screen_center_x) * (sx - screen_center_x) +
// 								(sy - screen_center_y) * (sy - screen_center_y));



// 	// Calculer le facteur de halo lumineux (plus proche du centre = plus lumineux)
// 	halo_factor = halo_intensity / (distance_to_center / 100.0 + 1.0);  // Ajustez "100.0f" pour ajuster la portée du halo

// 	// Calculer le facteur de distance pour ajuster la luminosité (pour l'effet de distance)
// 	distance_factor = 1.0 / (p->rc->perpWallDist + 1.0);

// 	// Calculer la luminosité finale (facteur de distance + halo)
// 	brightness = p->game->brightness * distance_factor * halo_factor;

// 	// Limiter la luminosité maximale pour éviter les débordements de couleur
// 	//if (brightness > 2.0f)  // Ajustez cette limite pour éviter une luminosité excessive
// 		//brightness = 2.0f;

// 	// Appliquer la luminosité aux composantes de couleur
// 	color = (uint8_t)(p->game->text->pixels[pixel] * brightness); // Rouge
// 	color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 1] * brightness); // Vert
// 	color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 2] * brightness); // Bleu
// 	color = (color << 8) + (uint8_t)(p->game->text->pixels[pixel + 3]); // Alpha

// 	return (color);
// }

// Calculer la position Y sur la texture en fonction de la hauteur du mur
static int	ft_define_ty(t_player *p, int sy)
{
	int	text_y;

	text_y = (int)((sy - p->rc->drawStart) * /*(float)*/p->game->text->height / (p->rc->drawEnd - p->rc->drawStart));
	if (text_y < 0)
		text_y = 0;

	//secure
	if (text_y >= p->game->text->height)
		text_y = p->game->text->height - 1; //if point is too big or too small : resize to smaller point or bigger from the texture.
	return (text_y);
}

//text_x is the coordinate of the wall we want to put texture
static int	ft_define_tx(t_player *p)
{
	int	text_x;


	text_x = (p->rc->wall_hit_position * (float)(p->game->text->width - 1));

	if(p->rc->side == 0 && p->rc->rayDirX > 0.0)
		text_x = p->game->text->width - text_x - 1;
	if(p->rc->side == 1 && p->rc->rayDirY < 0.0)
		text_x = p->game->text->width - text_x - 1;
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

	while (s[0] < p->rc->drawEnd)
	{
		// Calculer la position Y sur la texture en fonction de la hauteur du mur
		text_y = ft_define_ty(p, s[0]);

		//Because pixel is store in a char* and not a ray of ray (char**), we do :
		//text_y (wich is the y of pixel we want to put)
		// * the width of texture : like 6 * 64 (and the result is the line we want)
		//AND we add texture x for being not at the start of the line, but in the correct x pos.
		//Put it on escalidraw or come see me (or discord) if explaination needed
		//so it gives us this line :
		pixel = (p->game->text->width * text_y + text_x) * 4;
		//pixel need to be multiplicate by 4, because pixel is a group of 4 pixel (R + G + B + A)

		//verif if undo 0
		//if (pixel < 0)
			//pixel = 0;

		//and now that we have the index of the pixel in our ray, lets get the color of it :
		//we define the color of the pixel we'r gonna print
		color = ft_define_color(p, pixel);
		//color = ft_define_color(p, pixel, s[1], s[0]);

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

	color = 0xB400B4FF; //define color of the wall
	if (p->rc->side)
		color = (color / 2) | 0xFF;
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

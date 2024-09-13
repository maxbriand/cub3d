/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:47:18 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 18:07:02 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_put_floor(t_player *p, int s[2])
{
	uint32_t	color;

	color = p->data->map.floor_r;
	color = (color << 8) + p->data->map.floor_g;
	color = (color << 8) + p->data->map.floor_b;
	color = (color << 8) + 0xFF;
	while (s[0] < p->game->height)
	{
		mlx_put_pixel(p->game->image, s[1], s[0], color);
		s[0]++;
	}
}

static uint32_t	ft_define_color(t_player *p, uint32_t color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = ((color >> 24) & 0xFF) * p->rc->distance_factor;
	g = ((color >> 16) & 0xFF) * p->rc->distance_factor;
	b = ((color >> 8) & 0xFF) * p->rc->distance_factor;
	a = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static void	ft_put_floor_wall(t_player *p, int text_x, int s[2])
{
	int			pixel;
	int			text_y;

	if (p->rc->perp_wall_dist != p->rc->last_pwd)
	{
		p->rc->last_pwd = p->rc->perp_wall_dist;
		p->rc->distance_factor = 1.0 / (p->rc->perp_wall_dist + 1.0);
	}
	while (s[0] < p->rc->draw_end && s[0] != p->game->height - 1)
	{
		text_y = (int)((s[0] - p->rc->draw_start) * \
		(float)p->game->text->height / (p->rc->draw_end - p->rc->draw_start));
		pixel = (p->game->text->width * text_y + text_x);
		if (pixel < 0)
			pixel = 0;
		if (s[0] > 0 && s[0] < p->game->height && s[1] > 0 && s[1] < \
		p->game->width)
			mlx_put_pixel(p->game->image, s[1], s[0], ft_define_color(p, \
			p->game->color_ray_text[pixel]));
		s[0]++;
	}
	ft_put_floor(p, s);
}

void	ft_print_ray(t_player *p, int sx)
{
	int			s[2];
	int			text_x;
	uint32_t	color;

	text_x = (p->rc->wall_hit_position * (float)(p->game->text->width - 1));
	s[0] = 0;
	s[1] = sx;
	color = p->data->map.ceil_r;
	color = (color << 8) + p->data->map.ceil_g;
	color = (color << 8) + p->data->map.ceil_b;
	color = (color << 8) + 0xFF;
	while (s[0] < p->rc->draw_start)
	{
		mlx_put_pixel(p->game->image, s[1], s[0], color);
		s[0]++;
	}
	ft_put_floor_wall(p, text_x, s);
}

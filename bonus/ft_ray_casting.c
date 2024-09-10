/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:25:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 19:54:41 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_define_text_and_ray_color(t_player *p)
{
	if (p->rc->stepx == -1)
	{
		p->game->text = p->data->map.t_we_path;
		p->game->color_ray_text = p->game->color_west;
	}
	else
	{
		p->game->text = p->data->map.t_ea_path;
		p->game->color_ray_text = p->game->color_east;
	}
}

//define draw start and draw end, its were we should drow on the y line
static void	ft_define_print_wall(t_player *p)
{
	if (p->rc->side == 0)
		p->rc->perp_wall_dist = (p->rc->side_distx - p->rc->delta_distx);
	else
		p->rc->perp_wall_dist = (p->rc->side_disty - p->rc->delta_disty);
	p->rc->wall_height = ((float)p->game->height / (p->rc->perp_wall_dist * \
	(float)cos(p->or - p->rc->angle)));
	p->rc->wall_height = (float)floor(p->rc->wall_height * 10.0) / 10.0;
	p->rc->draw_start = -p->rc->wall_height / 2.0 + (float)p->game->mid_sy;
	p->rc->draw_end = p->rc->wall_height / 2.0 + (float)p->game->mid_sy;
	if (p->rc->side == 1)
	{
		if (p->rc->stepy == -1)
		{
			p->game->text = p->data->map.t_no_path;
			p->game->color_ray_text = p->game->color_north;
		}
		else
		{
			p->game->text = p->data->map.t_so_path;
			p->game->color_ray_text = p->game->color_south;
		}
	}
	else
		ft_define_text_and_ray_color(p);
}

//known what side of the wall we'r talking
static void	ft_find_side(t_player *p)
{
	while (p->rc->hit == 0)
	{
		if (p->rc->side_distx < p->rc->side_disty)
		{
			p->rc->side_distx += p->rc->delta_distx;
			p->rc->mapx += p->rc->stepx;
			p->rc->side = 0;
		}
		else
		{
			p->rc->side_disty += p->rc->delta_disty;
			p->rc->mapy += p->rc->stepy;
			p->rc->side = 1;
		}
		if (p->rc->mapy < 0 || p->rc->mapy >= p->data->map.height_map \
		|| p->rc->mapx < 0 || p->rc->mapx >= \
		(int)ft_strlen(p->data->map.map[p->rc->mapy]))
			p->rc->hit = 1;
		if (!p->rc->hit && p->data->map.map[p->rc->mapy][p->rc->mapx] == '1')
			p->rc->hit = 1;
	}
}

void	ft_ray_casting(void *param)
{
	t_player		*p;
	int				sx;
	struct timeval	time;
	suseconds_t		usec;
	time_t			sec;

	p = (t_player *)param;
	sx = 0;
	if (p->game->pause)
		return ;
	gettimeofday(&time, NULL);
	usec = time.tv_usec;
	sec = time.tv_sec;
	ft_move_wasd(p);
	while (sx < p->game->width)
	{
		ft_define_rc(p, sx);
		ft_find_side(p);
		ft_define_print_wall(p);
		ft_print_ray(p, sx);
		sx++;
	}
	gettimeofday(&time, NULL);
	ft_print_fps(p, usec, sec, time);
	ft_mouse_move(p);
}

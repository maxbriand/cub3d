/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:07:29 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/22 19:29:35 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mouse_move(t_player *p)
{
	int32_t	x;
	int32_t	y;

	if (p->game->cinematic)
		return ;
	if (!p->last_mouse_x)
		p->last_mouse_x = p->game->width / 2;
	mlx_get_mouse_pos(p->game->mlx, &x, &y);
	if (p->game->pause == false)
	{
		p->or += (x - p->last_mouse_x) * 0.001;
		mlx_set_mouse_pos(p->game->mlx, p->game->width / 2, \
		p->game->height / 2);
		p->last_mouse_x = p->game->width / 2;
	}

	if (p->game->cinematic == true)
		return ;
	if (!p->last_mouse_y)
		p->last_mouse_y = p->game->height / 2;
	if (p->game->pause == false)
	{
		p->p_look_angle -= (y - p->last_mouse_y) * 0.001;
		if (p->p_look_angle > 1.0)
			p->p_look_angle = 1.0;
		if (p->p_look_angle < -1.0)
			p->p_look_angle = -1.0;
		mlx_set_mouse_pos(p->game->mlx, p->game->width / 2, \
		p->game->height / 2);
		p->last_mouse_x = p->game->width / 2;
	}
}

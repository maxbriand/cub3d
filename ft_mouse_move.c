/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:07:29 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/23 02:04:08 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mouse_move(double x, double y, void *param)
{
	t_player	*p;

	p = (t_player *)param;

	if (p->game->pause == false)
	{
		p->or += (x - p->last_mouse_x) * 0.001;
		p->last_mouse_x = x;
		//mlx_set_mouse_pos(p->game->mlx, p->game->width / 2, p->game->height / 2);
	}

}
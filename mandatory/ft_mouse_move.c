/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:07:29 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/03 13:52:25 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_mouse_move(double x, double y, void *param)
{
	t_player	*p;

	p = (t_player *)param;

	if (p->game->pause == false)
	{
		//p->last_mouse_x = p->game->width / 2;
		p->or += (x - p->last_mouse_x) * 0.001;
		mlx_set_mouse_pos(p->game->mlx, p->game->width / 2, p->game->height / 2);
		p->last_mouse_x = p->game->width / 2; //on linux
		//p->last_mouse_x = x;// in WSL2
	}
}
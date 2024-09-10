/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:30:11 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 15:44:09 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_player	*p;

	p = (t_player *)param;

	//move from player
	if (p->game->pause == false)
		ft_move_hook(keydata, p);

	//HANDLE PAUSE GAME
	//if I put escape, then mause is show
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS && p->game->pause == false)
	{
		mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_NORMAL);
		p->game->pause = true;
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS && p->game->pause == true)
	{
		mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_HIDDEN);
		//mlx_set_mouse_pos(p->game->mlx, p->game->width / 2, p->game->height / 2);
		p->game->pause = false;
	}
}
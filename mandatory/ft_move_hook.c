/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:54:50 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 18:25:19 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_move_and_flashlight(mlx_key_data_t keydata, t_player *p)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		p->player_look_right = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		p->player_look_right = false;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		p->player_run = true;
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		p->player_run = false;
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS && !p->light_on)
	{
		p->light_on = true;
		p->game->dark->enabled = 0;
		p->game->flash->enabled = 1;
	}
	else if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS
		&& p->light_on)
	{
		p->light_on = false;
		p->game->dark->enabled = 1;
		p->game->flash->enabled = 0;
	}
}

//for bool to move or flashlight
void	ft_move_hook(mlx_key_data_t keydata, t_player *p)
{
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		p->player_move_f = true;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && \
		keydata.action != MLX_REPEAT)
		p->player_move_f = false;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p->player_move_b = true;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		p->player_move_b = false;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p->player_move_l = true;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		p->player_move_l = false;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p->player_move_r = true;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		p->player_move_r = false;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		p->player_look_left = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		p->player_look_left = false;
	ft_move_and_flashlight(keydata, p);
}

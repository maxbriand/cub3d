/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:54:50 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/02 03:13:12 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//sert a faire un truc kool
void	ft_move_hook(mlx_key_data_t keydata, t_player *p)
{
	//move front
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		p->player_move_f = true;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && keydata.action != MLX_REPEAT)
		p->player_move_f = false;

	//move back
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p->player_move_b = true;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		p->player_move_b = false;

	//move left
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p->player_move_l = true;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		p->player_move_l = false;

	//move left
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p->player_move_r = true;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		p->player_move_r = false;

	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		p->player_look_left = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		p->player_look_left = false;

	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		p->player_look_right = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		p->player_look_right = false;

}

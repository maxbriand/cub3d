/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:30:11 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/13 16:53:12 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_player	*p;

	p = (t_player *)param;
	if (p->game->pause == false)
		ft_move_hook(keydata, p);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS \
	&& p->game->pause == false)
	{
		mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_NORMAL);
		p->game->pause = true;
	}
	else if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS \
	&& p->game->pause == true)
	{
		mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_HIDDEN);
		p->game->pause = false;
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_ultimate_free(p);
}

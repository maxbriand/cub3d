/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:01:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/15 20:19:43 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	*ft_move_hook(void *param)
{
	t_player *p;
	
	p = (t_player *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		//need to change map from map parsed
		if(p->map[int(posX + dirX * moveSpeed)][int(posY)] == false)
			p->posX += p->rc->x * moveSpeed;
				
				//p->rc->rayDirX = cos(p->rc->angle);
				//p->rc->rayDirY = sin(p->rc->angle);
	
    	if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false)
			posY += dirY * moveSpeed;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:25:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/14 15:43:51 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//know what side of the wall we'r talking
static void	ft_find_side(t_player *p, char map[7][11])
{
	while (p->rc->hit == 0)
	{
		if (p->rc->sideDistX < p->rc->sideDistY)
		{
			p->rc->sideDistX += p->rc->deltaDistX;
			p->rc->mapX += p->rc->stepX;
			p->rc->side = 0;
		}
		else
		{
			p->rc->sideDistY += p->rc->deltaDistY;
			p->rc->mapY += p->rc->stepY;
			p->rc->side = 1;
		}
		if (p->rc->mapY < 0 || p->rc->mapY >= 7 || p->rc->mapX < 0 || p->rc->mapX >= (int)ft_strlen(map[p->rc->mapY]))
			p->rc->hit = 1;
		if (map[p->rc->mapY][p->rc->mapX] == '1')
			p->rc->hit = 1;
	}
}

void	ft_ray_casting(t_player *p, char map[7][11])
{
	int	ex;

	ex = 0;
	while (ex < p->game->width)
	{
		//we redefine rc every frame, because it set var needed by ray casting
		ft_define_rc(p, ex);
		//know what side of the wall we'r talking
		ft_find_side(p, map);

		//calcul to remove fishy
		
		if(p->rc->side == 0)
			p->rc->perpWallDist = (p->rc->sideDistX - p->rc->deltaDistX);
    	else
			p->rc->perpWallDist = (p->rc->sideDistY - p->rc->deltaDistY);
		// float distance = sqrt(pow(x - posX, 2.0) + pow(y - posY, 2.0));
		// float Wall_height = (height / ((distance * cos(or - angle)) / 100.0));
		p->rc->wall_height = (p->game->height / (p->rc->perpWallDist * cos(p->or - p->rc->angle))); // change
		p->rc->wall_height = floor(p->rc->wall_height * 10.0) / 10.0;
		//fin


		//dessiner le rayon :
		p->rc->drawStart = - p->rc->wall_height / 2.0 + (float)p->game->height / 2.0;
		p->rc->drawEnd = p->rc->wall_height / 2.0 + (float)p->game->height / 2.0;
		if (p->rc->drawStart < 0)
			p->rc->drawStart = 0;
		if (p->rc->drawEnd >= p->game->height)
			p->rc->drawEnd = p->game->height - 1.0;
		int k =0;
		int	color = 0xB400B4FF;
		if (p->rc->side)
			color = (color / 2) | 0xFF;
		while (k < p->rc->drawStart)
		{
			mlx_put_pixel(p->game->image, ex, k, 0x0000B4FF); // Violet pour le mur
			k++;
		}
		while (k < p->rc->drawEnd)
		{
			mlx_put_pixel(p->game->image, ex, k, color); // Violet pour le mur
			k++;
		}
		k -= 2;
		while (k < p->game->height)
		{
			mlx_put_pixel(p->game->image, ex, k, 0x000000FF); // Violet pour le mur
			k++;
		}
		//end print

		ex++;
	}
}
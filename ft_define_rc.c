/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_rc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:01:15 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/13 17:59:32 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_ray_calcul(t_player *p)
{
	if (p->rc->rayDirX < 0)
	{
		p->rc->stepX = -1;
		p->rc->sideDistX = (p->posX - p->rc->mapX) * p->rc->deltaDistX;
	}
	else
	{
		p->rc->stepX = 1;
		p->rc->sideDistX = (p->rc->mapX + 1.0 - p->posX) * p->rc->deltaDistX;
	}
	if (p->rc->rayDirY < 0)
	{
		p->rc->stepY = -1;
		p->rc->sideDistY = (p->posY - p->rc->mapY) * p->rc->deltaDistY;
	}
	else
	{
		p->rc->stepY = 1;
		p->rc->sideDistY = (p->rc->mapY + 1.0 - p->posY) * p->rc->deltaDistY;
	}
}

void	ft_define_rc(t_player *p, int ex)
{
	p->rc = malloc(sizeof(*p->rc));
	p->rc->y = p->posY;
	p->rc->x = p->posX;
	//trouver la longueur du rayon
	p->rc->angle = p->or - (p->fov / 2.0) + (p->fov * ((float)ex / p->game->width));
	p->rc->rayDirX = cos(p->rc->angle);
	p->rc->rayDirY = sin(p->rc->angle);
	p->rc->hit = 0;

	p->rc->mapX = (int)p->posX;
	p->rc->mapY = (int)p->posY;


	p->rc->deltaDistX = sqrt(1.0 + (p->rc->rayDirY * p->rc->rayDirY) / (p->rc->rayDirX * p->rc->rayDirX));
	p->rc->deltaDistY = sqrt(1.0 + (p->rc->rayDirX * p->rc->rayDirX) / (p->rc->rayDirY * p->rc->rayDirY));


	//calcule des rayon
	ft_ray_calcul(p);
}

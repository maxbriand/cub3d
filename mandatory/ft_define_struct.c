/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:21 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 14:28:26 by gmersch          ###   ########.fr       */
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
	if (!p->rc)
		p->rc = malloc(sizeof(*p->rc));
	//trouver la longueur du rayon
	p->rc->angle = p->or - (p->fov / 2.0) + (p->fov * ((float)ex / (float)p->game->width));
	p->rc->rayDirX = cos(p->rc->angle);
	p->rc->rayDirY = sin(p->rc->angle);
	p->rc->hit = 0;

	p->rc->mapX = (int)p->posX;
	p->rc->mapY = (int)p->posY;


	p->rc->deltaDistX = sqrt(1.0 + (p->rc->rayDirY * p->rc->rayDirY) / (p->rc->rayDirX * p->rc->rayDirX));
	p->rc->deltaDistY = sqrt(1.0 + (p->rc->rayDirX * p->rc->rayDirX) / (p->rc->rayDirY * p->rc->rayDirY));

	if (p->rc->side == 0) // Mur vertical (nord-sud)
		p->rc->wall_hit_position = p->posY + p->rc->perpWallDist * p->rc->rayDirY;
	else // Mur horizontal (est-ouest)
		p->rc->wall_hit_position = p->posX + p->rc->perpWallDist * p->rc->rayDirX;
	p->rc->wall_hit_position -= floor(p->rc->wall_hit_position);



	//calcule des rayon
	ft_ray_calcul(p);
}

static t_game	*ft_define_game()
{
	t_game	*game;

	game = malloc(sizeof(*game));
	game->width = 1920;
	game->height = 1080;
	game->pause = false;
	game->mlx = mlx_init(game->width, game->height, "Cube3D", true);
	game->image = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->image)
	{
		mlx_terminate(game->mlx);
		return (NULL);
	}
	game->text = NULL;





	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	return (game);
}


t_player	*ft_define_player()
{
	//PLAYER NEED TO BE SET WITH PARSING, NOT LIKE THIS
	t_player	*p;

	p = malloc(sizeof(*p));
	p->game = ft_define_game();
		//if (!mlx_game) need to put pointer
		//return (-1);
	p->posX = 8.50;
	p->posY = 3.50; //x and y start position

	p->move_speed = 0.05;
	p->player_move_f = false;
	p->player_move_b = false;
	p->player_move_l = false;
	p->player_move_r = false;

	p->last_mouse_x = 0;
	p->last_mouse_y = 0;


	p->fov = M_PI * 0.4;
	p->or = 1 * M_PI;
	p->rc = NULL;
	return (p);
}

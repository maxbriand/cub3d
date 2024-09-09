/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:21 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/09 02:55:01 by gmersch          ###   ########.fr       */
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
	{
		p->rc = ft_calloc(sizeof(*p->rc), 1);
		p->rc->last_pwd = 0;
		p->rc->distance_factor = 0;
	}
	//trouver la longueur du rayon
	p->rc->angle = p->or - (p->fov / 2.0) + (p->fov * ((float)ex / (float)p->game->width));
	p->rc->rayDirX = cos(p->rc->angle);
	p->rc->rayDirY = sin(p->rc->angle);
	p->rc->hit = 0;

	p->rc->mapX = (int)p->posX;
	p->rc->mapY = (int)p->posY;


	//p->rc->deltaDistX = sqrt(1.0 + (p->rc->rayDirY * p->rc->rayDirY) / (p->rc->rayDirX * p->rc->rayDirX));
	//p->rc->deltaDistY = sqrt(1.0 + (p->rc->rayDirX * p->rc->rayDirX) / (p->rc->rayDirY * p->rc->rayDirY));

	p->rc->deltaDistX = fabs(1 / p->rc->rayDirX);
	p->rc->deltaDistY = fabs(1 / p->rc->rayDirY);
	//deltadist = abs(1/sidedist)


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
	//game->width = 1920;
	game->width = 720;
	//game->height = 1080;
	game->height = 480;
	game->mid_sx = game->width / 2;
	game->mid_sy = game->height / 2;
	game->pause = false;
	game->mlx = mlx_init(game->width, game->height, "Cube3D", false);
	game->image = mlx_new_image(game->mlx, game->width, game->height);

	if (!game->image)
	{
		mlx_terminate(game->mlx);
		return (NULL);
	}
	game->text = NULL;
	game->fps = NULL;
	game->fps_max = NULL;
	game->fps_min = NULL;
	game->fps_mini = NULL;
	game->fps_maxi = NULL;



	game->brightness = 1.0; //sombre ??

	game->dark_t =  mlx_load_png("parsing/textures/dark.png");
	game->flash_t =  mlx_load_png("parsing/textures/lampe85.png");
	game->dark = mlx_texture_to_image(game->mlx, game->dark_t);
	game->flash = mlx_texture_to_image(game->mlx, game->flash_t);
	//PROCTECT IMAGE !!!


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
	p->player_run = false;
	p->player_move_f = false;
	p->player_move_b = false;
	p->player_move_l = false;
	p->player_move_r = false;
	p->player_look_left = false;
	p->player_look_right = false;
	p->light_on = true;

	p->last_mouse_x = 0;
	p->last_mouse_y = 0;


	p->fov = M_PI * 0.4;
	p->or = 1 * M_PI;
	p->rc = NULL;
	return (p);
}

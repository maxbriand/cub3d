/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:21 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 15:43:45 by gmersch          ###   ########.fr       */
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

	p->rc->deltaDistX = fabs(1 / p->rc->rayDirX);//mayday
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

static void	ft_define_game(t_player *p)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_ultimate_free(p);
	p->game = game;
	//480p
	p->game->width = 854;
	p->game->height = 480;
	p->game->mid_sx = p->game->width / 2;
	p->game->mid_sy = p->game->height / 2;
	p->game->mlx = mlx_init(p->game->width, p->game->height, "Cube3D", true);
	if (!p->game->mlx)
		ft_ultimate_free(p);
	p->game->brightness = 1.0; //sombre ??
	p->game->image = mlx_new_image(p->game->mlx, p->game->width, p->game->height);
	p->game->dark_t =  mlx_load_png("parsing/textures/dark480p.png");
	p->game->flash_t =  mlx_load_png("parsing/textures/lampe480p.png");
	p->game->dark = mlx_texture_to_image(p->game->mlx, p->game->dark_t);
	p->game->flash = mlx_texture_to_image(p->game->mlx, p->game->flash_t);
	if (!p->game->dark_t || !p->game->flash_t || !p->game->dark
		|| !p->game->flash || !p->game->image)
		ft_ultimate_free(p);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_set_setting(MLX_FULLSCREEN, 1);
}

t_player	*ft_define_player(t_data *data)
{
	//PLAYER NEED TO BE SET WITH PARSING, NOT LIKE THIS
	t_player	*p;

	p = ft_calloc(sizeof(*p), 1);
	p->data = data;
	ft_define_game(p);
	p->posX = (float)p->data->x_spoint + 0.5;
	p->posY = (float)p->data->y_spoint + 0.5;; //x and y start position
	p->move_speed = 0.05;
	p->light_on = true;
	p->fov = 0.5 * M_PI;
	if (p->data->map.spawning_orientation == 'N')
		p->or = 1.5 * M_PI;
	if (p->data->map.spawning_orientation == 'E')
		p->or = 0.0 * M_PI;
	if (p->data->map.spawning_orientation == 'S')
		p->or = 0.5 * M_PI;
	if (p->data->map.spawning_orientation == 'W')
		p->or = 1.0 * M_PI;
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:21 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/22 21:48:50 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_ray_calcul(t_player *p)
{
	if (p->rc->ray_dirx < 0)
	{
		p->rc->stepx = -1;
		p->rc->side_distx = (p->posx - p->rc->mapx) * p->rc->delta_distx;
	}
	else
	{
		p->rc->stepx = 1;
		p->rc->side_distx = (p->rc->mapx + 1.0 - p->posx) * p->rc->delta_distx;
	}
	if (p->rc->ray_diry < 0)
	{
		p->rc->stepy = -1;
		p->rc->side_disty = (p->posy - p->rc->mapy) * p->rc->delta_disty;
	}
	else
	{
		p->rc->stepy = 1;
		p->rc->side_disty = (p->rc->mapy + 1.0 - p->posy) * p->rc->delta_disty;
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
	p->rc->angle = p->or - (p->fov / 2.0) + (p->fov * ((float)ex / \
	(float)p->game->width));
	p->rc->ray_dirx = cos(p->rc->angle);
	p->rc->ray_diry = sin(p->rc->angle);
	p->rc->hit = 0;
	p->rc->mapx = (int)p->posx;
	p->rc->mapy = (int)p->posy;
	p->rc->delta_distx = fabs(1 / p->rc->ray_dirx);
	p->rc->delta_disty = fabs(1 / p->rc->ray_diry);
	if (p->rc->side == 0)
		p->rc->wall_hit_position = p->posy + p->rc->perp_wall_dist * \
		p->rc->ray_diry;
	else
		p->rc->wall_hit_position = p->posx + p->rc->perp_wall_dist * \
		p->rc->ray_dirx;
	p->rc->wall_hit_position -= floor(p->rc->wall_hit_position);
	ft_ray_calcul(p);
}



void	ft_check_and_resize(t_player *p)
{
	p->game->fullscreen = true;
	p->game->cinematic = true;
	p->game->color_north = ft_calloc(sizeof(uint32_t), \
	(p->data->map.t_no_path->height * p->data->map.t_no_path->width) + 1);
	p->game->color_south = ft_calloc(sizeof(uint32_t), \
	(p->data->map.t_so_path->height * p->data->map.t_so_path->width) + 1);
	p->game->color_west = ft_calloc(sizeof(uint32_t), \
	(p->data->map.t_we_path->height * p->data->map.t_we_path->width) + 1);
	p->game->color_east = ft_calloc(sizeof(uint32_t), \
	(p->data->map.t_ea_path->height * p->data->map.t_ea_path->width) + 1);
	if (!p->game->color_north || !p->game->color_south || !p->game->color_west
		|| !p->game->color_east || !p->game->dark || !p->game->flash
		|| !p->game->image)
		ft_ultimate_free(p);
	mlx_set_window_size(p->game->mlx, 1920, 1080);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_FULLSCREEN, true);
	mlx_set_setting(MLX_MAXIMIZED, true);
}

static void	ft_define_game(t_player *p)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(*game));
	if (!game)
		ft_ultimate_free(p);
	p->game = game;
	p->game->width = 854;
	p->game->height = 480;
	p->game->mid_sx = p->game->width / 2;
	p->game->mid_sy = p->game->height / 2;
	p->game->mlx = mlx_init(p->game->width, p->game->height, "Cube3D", true);
	if (!p->game->mlx)
		ft_ultimate_free(p);
	p->game->dark_t = mlx_load_png("parsing/textures/dark480p.png");
	p->game->flash_t = mlx_load_png("parsing/textures/lampe480p.png");
	if (!p->game->dark_t || !p->game->flash_t)
		ft_ultimate_free(p);
	p->game->image = mlx_new_image(p->game->mlx, p->game->width, \
	p->game->height);
	p->game->dark = mlx_texture_to_image(p->game->mlx, p->game->dark_t);
	p->game->flash = mlx_texture_to_image(p->game->mlx, p->game->flash_t);
	p->game->flash->enabled = 1;
	p->game->dark->enabled = 0;
	ft_check_and_resize(p);
	ft_define_color_text(p);
}

static t_freddy	*ft_define_freddy(t_player *p)
{
	t_freddy *f;
	f = ft_calloc(1, sizeof(*f));
	if (!f)
		ft_ultimate_free(p);
	f->freddy_left = mlx_load_png("parsing/textures/leftfreddy.png");
	f->freddy_right = mlx_load_png("parsing/textures/rightfreddy.png");
	f->freddy_right = mlx_load_png("parsing/textures/rightfreddy.png");
	f->flook = mlx_load_png("parsing/textures/flook.png");
	f->fgolden = mlx_load_png("parsing/textures/goldenf.png");
	if (!f->freddy_left || !f->freddy_right || !f->flook || !f->fgolden)
		ft_ultimate_free(p);
	f->fl = mlx_texture_to_image(p->game->mlx, f->freddy_left);
	f->fr = mlx_texture_to_image(p->game->mlx, f->freddy_right);
	f->look =  mlx_texture_to_image(p->game->mlx, f->flook);
	f->golden =  mlx_texture_to_image(p->game->mlx, f->fgolden);
	f->golden->enabled = false;
	mlx_resize_image(f->golden, 1700, 1700);
	if (!f->fl || !f->fr || !f->look)
		ft_ultimate_free(p);
	f->posx = 9.0;
	f->posy = 4.0; //a redefinir
	f->right = false;
	return (f);
}

t_player	*ft_define_player(t_data *data)
{
	t_player	*p;

	p = ft_calloc(sizeof(*p), 1);
	p->data = data;
	ft_define_game(p);
	p->f = ft_define_freddy(p);
	p->posx = (float)p->data->x_spoint + 0.5;
	p->posy = (float)p->data->y_spoint + 0.5;
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

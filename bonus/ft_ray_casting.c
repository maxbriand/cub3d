/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:25:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 15:32:15 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_print_fps(t_player *p, suseconds_t usec, time_t sec, struct timeval time)
{
	char	*fps;

	if (p->game->fps)
		mlx_delete_image(p->game->mlx, p->game->fps);
	if (time.tv_sec == sec)
	{
		fps = ft_itoa((int)(1000000 / (time.tv_usec - usec)));
		if (!fps)
			ft_ultimate_free(p);
		if (!p->game->fps_mini || ft_atoi(p->game->fps_mini) > ft_atoi(fps))
		{
			if (p->game->fps_min)
				mlx_delete_image(p->game->mlx, p->game->fps_min);
			if (p->game->fps_mini)
				free(p->game->fps_mini);
			p->game->fps_mini = ft_strdup(fps);
			if (!p->game->fps_mini)
				ft_ultimate_free(p);
			p->game->fps_min = mlx_put_string(p->game->mlx, p->game->fps_mini, 50, 10);
			if (!p->game->fps_min)
				ft_ultimate_free(p);
		}
		if (!p->game->fps_maxi || ft_atoi(p->game->fps_maxi) < ft_atoi(fps))
		{
			if (p->game->fps_max)
				mlx_delete_image(p->game->mlx, p->game->fps_max);
			if (p->game->fps_maxi)
				free(p->game->fps_maxi);
			p->game->fps_maxi = ft_strdup(fps);
			if (!p->game->fps_maxi)
				ft_ultimate_free(p);
			p->game->fps_max = mlx_put_string(p->game->mlx, p->game->fps_maxi, 80, 10);
		}
		p->game->fps = mlx_put_string(p->game->mlx, fps, 10, 10);
		if (!p->game->fps_max || !p->game->fps)
			ft_ultimate_free(p);
		free(fps);
	}
}

//define draw start and draw end, its were we should drow on the y line (vertical line)
static void	ft_define_print(t_player *p)
{
	p->rc->drawStart = - p->rc->wall_height / 2.0 + (float)p->game->mid_sy;
	p->rc->drawEnd = p->rc->wall_height / 2.0 + (float)p->game->mid_sy;

	//define text
	if (p->rc->side == 1)
	{
		if (p->rc->stepY == -1)
		{
			p->game->text = p->data->map.t_no_path;
			p->game->color_ray_text = p->game->color_north;
		}
		else
		{
			p->game->text =  p->data->map.t_so_path;
			p->game->color_ray_text = p->game->color_south;
		}
	}
	else
	{
		if (p->rc->stepX == -1)
		{
			p->game->text =  p->data->map.t_we_path;
			p->game->color_ray_text = p->game->color_west;
		}
		else
		{
			p->game->text =  p->data->map.t_ea_path;
			p->game->color_ray_text = p->game->color_east;
		}
	}
}

static void	ft_calcul_wall(t_player *p)
{
	//calcul to remove fishy
	if(p->rc->side == 0)
		p->rc->perpWallDist = (p->rc->sideDistX - p->rc->deltaDistX);
	else
		p->rc->perpWallDist = (p->rc->sideDistY - p->rc->deltaDistY);
	//find wallheight

	p->rc->wall_height = ((float)p->game->height / (p->rc->perpWallDist * (float)cos(p->or - p->rc->angle))); // change
	p->rc->wall_height = (float)floor(p->rc->wall_height * 10.0) / 10.0;
}

//know what side of the wall we'r talking
static void	ft_find_side(t_player *p)
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
		//change//if (p->rc->mapY < 0 || p->rc->mapY >= 7 || p->rc->mapX < 0 || p->rc->mapX >= (int)ft_strlen(p->data->map.map[p->rc->mapY]))
		if (p->rc->mapY < 0 || p->rc->mapY >= p->data->map.height_map || p->rc->mapX < 0 || p->rc->mapX >= (int)ft_strlen(p->data->map.map[p->rc->mapY]))
			p->rc->hit = 1;
		if (!p->rc->hit && p->data->map.map[p->rc->mapY][p->rc->mapX] == '1')
			p->rc->hit = 1;
	}
}

void	ft_ray_casting(void *param)
{
	t_player		*p;
	int				sx; //screen x
	struct timeval	time; // add fps counter
	suseconds_t		usec;
	time_t			sec;

	p = (t_player *)param;
	sx = 0;
	if (p->game->pause)
		return ;
	gettimeofday(&time, NULL);
	usec = time.tv_usec;
	sec = time.tv_sec;
	ft_move_wasd(p);//ici;
	while (sx < p->game->width)
	{
		//we redefine rc every frame, because it set var needed by ray casting
		ft_define_rc(p, sx);
		//know what side of the wall we'r talking
		ft_find_side(p);
		//calcul wall height and remove fishy
		ft_calcul_wall(p);
		//define draw start and draw end
		ft_define_print(p);
		//print ray, its here to change color :
		ft_print_ray(p, sx);
		sx++;
	}
	//print fps
	gettimeofday(&time, NULL);
	ft_print_fps(p, usec, sec, time);



	//mouse move
	int32_t x;
	int32_t y;

	if (!p->last_mouse_x)
		p->last_mouse_x = p->game->width / 2;
	mlx_get_mouse_pos(p->game->mlx, &x, &y);
	if (p->game->pause == false)
	{
		//p->last_mouse_x = p->game->width / 2;
		p->or += (x - p->last_mouse_x) * 0.001;
		mlx_set_mouse_pos(p->game->mlx, p->game->width / 2, p->game->height / 2);
		p->last_mouse_x = p->game->width / 2; //on linux
		//p->last_mouse_x = x;// in WSL2
	}
	//ft_mouse_move(p);
}

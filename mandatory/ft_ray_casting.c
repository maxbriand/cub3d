/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:25:10 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/02 03:18:04 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_print_fps(t_player *p, suseconds_t usec, time_t sec, struct timeval time)
{
	char	*fps;

	if (time.tv_sec == sec)
	{
		fps = ft_itoa((int)(1000000 / (time.tv_usec - usec)));
		printf("%s\n", fps); //fps
		//mlx_put_string(p->game->mlx, fps, 10, 10);
	}
}

//define draw start and draw end, its were we should drow on the y line (vertical line)
static void	ft_define_print(t_player *p)
{
	p->rc->drawStart = - p->rc->wall_height / 2.0 + (float)p->game->height / 2.0;
	p->rc->drawEnd = p->rc->wall_height / 2.0 + (float)p->game->height / 2.0;
	if (p->rc->drawStart < 0)
		p->rc->drawStart = 0;
	if (p->rc->drawEnd >= p->game->height)
		p->rc->drawEnd = p->game->height - 1.0;

	//define text
	if (p->rc->side == 1)
	{
		if (p->rc->stepY == -1)
			p->game->text = p->data->map.t_no_path;
		else
			p->game->text =  p->data->map.t_so_path;
	}
	else
	{
		if (p->rc->stepX == -1)
			p->game->text =  p->data->map.t_we_path;
		else
			p->game->text =  p->data->map.t_ea_path;
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
	p->rc->wall_height = (p->game->height / (p->rc->perpWallDist * cos(p->or - p->rc->angle))); // change
	p->rc->wall_height = floor(p->rc->wall_height * 10.0) / 10.0;
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
		if (p->rc->mapY < 0 || p->rc->mapY >= 7 || p->rc->mapX < 0 || p->rc->mapX >= (int)ft_strlen(p->data->map.map[p->rc->mapY]))
			p->rc->hit = 1;
		if (p->data->map.map[p->rc->mapY][p->rc->mapX] == '1')
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:01:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 18:25:58 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_move_right(t_player *p)
{
	int	new_posx;
	int	new_posy;

	new_posx = (int)(p->posx + cos(p->or + (M_PI / 2)) * p->move_speed);
	new_posy = (int)(p->posy + sin(p->or + (M_PI / 2)) * p->move_speed);
	if (p->data->map.map[new_posy][(int)p->posx] != '1' \
		&& p->data->map.map[(int)p->posy][new_posx] != '1')
	{
		p->posx += cos(p->or + (M_PI / 2)) * p->move_speed;
		p->posy += sin(p->or + (M_PI / 2)) * p->move_speed;
	}
}

static void	ft_move_left(t_player *p)
{
	int	new_posx;
	int	new_posy;

	new_posx = (int)(p->posx + cos(p->or - (M_PI / 2)) * p->move_speed);
	new_posy = (int)(p->posy + sin(p->or - (M_PI / 2)) * p->move_speed);
	if (p->data->map.map[new_posy][(int)p->posx] != '1' \
		&& p->data->map.map[(int)p->posy][new_posx] != '1')
	{
		p->posx += cos(p->or - (M_PI / 2)) * p->move_speed;
		p->posy += sin(p->or - (M_PI / 2)) * p->move_speed;
	}
}

static void	ft_move_backward(t_player *p)
{
	int	new_posx;
	int	new_posy;

	new_posx = (int)(p->posx - cos(p->or) * p->move_speed);
	new_posy = (int)(p->posy - sin(p->or) * p->move_speed);
	if (p->data->map.map[new_posy][(int)p->posx] != '1' \
		&& p->data->map.map[(int)p->posy][new_posx] != '1')
	{
		p->posx -= cos(p->or) * p->move_speed;
		p->posy -= sin(p->or) * p->move_speed;
	}
}

static void	ft_move_forward(t_player *p)
{
	int	new_posx;
	int	new_posy;

	new_posx = (int)(p->posx + cos(p->or) * p->move_speed);
	new_posy = (int)(p->posy + sin(p->or) * p->move_speed);
	if (p->data->map.map[new_posy][(int)p->posx] != '1' \
		&& p->data->map.map[(int)p->posy][new_posx] != '1')
	{
		p->posx += cos(p->or) * p->move_speed;
		p->posy += sin(p->or) * p->move_speed;
	}
}

void	ft_move_wasd(t_player *p)
{
	if (p->player_run)
		p->move_speed = 0.1;
	else
		p->move_speed = 0.05;
	if (p->player_move_f)
		ft_move_forward(p);
	if (p->player_move_b)
		ft_move_backward(p);
	if (p->player_move_l)
		ft_move_left(p);
	if (p->player_move_r)
		ft_move_right(p);
	if (p->player_look_left)
		p->or -= 0.05;
	if (p->player_look_right)
		p->or += 0.05;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:01:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/02 03:14:25 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_move_right(t_player *p)
{
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall on left
	newPosX = (int)(p->posX + cos(p->or+ (M_PI / 2)) * p->move_speed);
	newPosY = (int)(p->posY + sin(p->or + (M_PI / 2)) * p->move_speed);

	if (p->data->map.map[newPosY][(int)p->posX] != '1' && p->data->map.map[(int)p->posY][newPosX] != '1')
	{
		p->posX += cos(p->or + (M_PI / 2)) * p->move_speed;
		p->posY += sin(p->or + (M_PI / 2)) * p->move_speed;
	}
}

static void	ft_move_left(t_player *p)
{
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall on left
	newPosX = (int)(p->posX + cos(p->or - (M_PI / 2)) * p->move_speed);
	newPosY = (int)(p->posY + sin(p->or - (M_PI / 2)) * p->move_speed);

	if (p->data->map.map[newPosY][(int)p->posX] != '1' && p->data->map.map[(int)p->posY][newPosX] != '1')
	{
		p->posX += cos(p->or - (M_PI / 2)) * p->move_speed;
		p->posY += sin(p->or - (M_PI / 2)) * p->move_speed;
	}
}

static void	ft_move_backward(t_player *p)
{
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall behind
	newPosX = (int)(p->posX - cos(p->or) * p->move_speed);
	newPosY = (int)(p->posY - sin(p->or) * p->move_speed);

	if (p->data->map.map[newPosY][(int)p->posX] != '1' && p->data->map.map[(int)p->posY][newPosX] != '1')
	{
		p->posX -= cos(p->or) * p->move_speed;
		p->posY -= sin(p->or) * p->move_speed;
	}
}

static void	ft_move_forward(t_player *p)
{
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall front
	newPosX = (int)(p->posX + cos(p->or) * p->move_speed);
	newPosY = (int)(p->posY + sin(p->or) * p->move_speed);

	if (p->data->map.map[newPosY][(int)p->posX] != '1' && p->data->map.map[(int)p->posY][newPosX] != '1')
	{
		p->posX += cos(p->or) * p->move_speed;
		p->posY += sin(p->or) * p->move_speed;
	}
}

void	ft_move_wasd(t_player *p)
{
	//move front
	if (p->player_move_f)
		ft_move_forward(p);

	//move back
	if (p->player_move_b)
		ft_move_backward(p);

	//move left
	if (p->player_move_l)
		ft_move_left(p);

	//move right
	if (p->player_move_r)
		ft_move_right(p);

	if (p->player_look_left)
		p->or -= 0.04;
	if (p->player_look_right)
		p->or += 0.04;
}

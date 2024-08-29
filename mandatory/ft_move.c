/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:01:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/29 03:08:02 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_move_right(t_player *p)
{
	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall on left
	newPosX = (int)(p->posX + cos(p->or+ (M_PI / 2)) * p->move_speed);
	newPosY = (int)(p->posY + sin(p->or + (M_PI / 2)) * p->move_speed);

	if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
	{
		p->posX += cos(p->or + (M_PI / 2)) * p->move_speed;
		p->posY += sin(p->or + (M_PI / 2)) * p->move_speed;
	}
}

static void	ft_move_left(t_player *p)
{
	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall on left
	newPosX = (int)(p->posX + cos(p->or - (M_PI / 2)) * p->move_speed);
	newPosY = (int)(p->posY + sin(p->or - (M_PI / 2)) * p->move_speed);

	if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
	{
		p->posX += cos(p->or - (M_PI / 2)) * p->move_speed;
		p->posY += sin(p->or - (M_PI / 2)) * p->move_speed;
	}
}

static void	ft_move_backward(t_player *p)
{
	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall behind
	newPosX = (int)(p->posX - cos(p->or) * p->move_speed);
	newPosY = (int)(p->posY - sin(p->or) * p->move_speed);

	if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
	{
		p->posX -= cos(p->or) * p->move_speed;
		p->posY -= sin(p->or) * p->move_speed;
	}
}

static void	ft_move_forward(t_player *p)
{
	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};
	int	newPosX;
	int	newPosY;

	//calcul if there is a wall front
	newPosX = (int)(p->posX + cos(p->or) * p->move_speed);
	newPosY = (int)(p->posY + sin(p->or) * p->move_speed);

	if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
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
}

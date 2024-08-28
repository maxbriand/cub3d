/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:01:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/28 23:54:12 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//sert a faire un truc kool
void	ft_move_hook(mlx_key_data_t keydata, t_player *p)
{


	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};

	//move front
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		//printf("input = %d\n", p->player_move_f == true);
		p->player_move_f = true;
	}
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && keydata.action != MLX_REPEAT)
	{
		//printf("test\n");
		p->player_move_f = false;
	}

	//move back
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p->player_move_b = true;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		p->player_move_b = false;

	//move left
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p->player_move_l = true;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		p->player_move_l = false;

	//move left
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p->player_move_r = true;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		p->player_move_r = false;
}

void	ft_move_wasd(t_player *p)
{
	int			newPosX;
	int			newPosY;

	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};

	//move front
	if (p->player_move_f)
	{
		//calcul if there is a wall front
		newPosX = (int)(p->posX + cos(p->or) * p->move_speed);
		newPosY = (int)(p->posY + sin(p->or) * p->move_speed);

		if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
		{
			p->posX += cos(p->or) * p->move_speed;
			p->posY += sin(p->or) * p->move_speed;
		}
	}
	//move back
	if (p->player_move_b)
	{
		//calcul if there is a wall behind
		newPosX = (int)(p->posX - cos(p->or) * p->move_speed);
		newPosY = (int)(p->posY - sin(p->or) * p->move_speed);

		if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
		{
			p->posX -= cos(p->or) * p->move_speed;
			p->posY -= sin(p->or) * p->move_speed;
		}
	}
	//move left
	if (p->player_move_l)
	{
		//calcul if there is a wall on left
		newPosX = (int)(p->posX + cos(p->or - (M_PI / 2)) * p->move_speed);
		newPosY = (int)(p->posY + sin(p->or - (M_PI / 2)) * p->move_speed);

		if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
		{
			p->posX += cos(p->or - (M_PI / 2)) * p->move_speed;
			p->posY += sin(p->or - (M_PI / 2)) * p->move_speed;

			//mlx_set_mouse_pos
		}
	}
	if (p->player_move_r)
	{
		//calcul if there is a wall on left
		newPosX = (int)(p->posX + cos(p->or+ (M_PI / 2)) * p->move_speed);
		newPosY = (int)(p->posY + sin(p->or + (M_PI / 2)) * p->move_speed);

		if (map[newPosY][(int)p->posX] == '0' && map[(int)p->posY][newPosX] == '0')
		{
			p->posX += cos(p->or + (M_PI / 2)) * p->move_speed;
			p->posY += sin(p->or + (M_PI / 2)) * p->move_speed;
		}
	}
}
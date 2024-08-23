/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:36:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/23 02:07:48 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
	t_player *p;

	p = ft_define_player();

	//need to be define by parsing
	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};

	//ray casting and print on screen
	mlx_loop_hook(p->game->mlx, ft_ray_casting, p); //map will be in struct set by pars ?
	mlx_image_to_window(p->game->mlx, p->game->image, 0, 0);
	mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_HIDDEN);

	//mlx_set_mouse_pos(p->game->mlx, p->game->width / 2,p->game->height / 2);

	//mlx_key_hook(p->game->mlx, &ft_move_hook, p);
	mlx_key_hook(p->game->mlx, &ft_key_hook, p);
	mlx_cursor_hook(p->game->mlx, &ft_mouse_move, p);
	mlx_loop(p->game->mlx);
	mlx_delete_image(p->game->mlx, p->game->image);
	mlx_terminate(p->game->mlx);
	ft_ultimate_free(p);
	return (0);
}
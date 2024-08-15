/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:36:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/14 15:33:00 by gmersch          ###   ########.fr       */
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

	ft_ray_casting(p, map); //map will be in struct set by pars ?
	
	
	mlx_image_to_window(p->game->mlx, p->game->image, 0, 0);
	//mlx_loop_hook(mlx, move_hook(), t_)
	mlx_loop(p->game->mlx);
	mlx_delete_image(p->game->mlx, p->game->image);
	mlx_terminate(p->game->mlx);
	ft_ultimate_free(p);
	return (0);
}

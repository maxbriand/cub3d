/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:36:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/02 03:18:32 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_player	*p;
	t_data		*data;

	ft_parsing(data, argc, argv);
	ft_init_png(data);
	p = ft_define_player();
	p->data = data;

	//ray casting and print on screen
	mlx_loop_hook(p->game->mlx, ft_ray_casting, p); //map will be in struct set by pars ?
	mlx_image_to_window(p->game->mlx, p->game->image, 0, 0);
	mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_HIDDEN);

	//mlx_key_hook(p->game->mlx, &ft_move_hook, p);
	mlx_key_hook(p->game->mlx, &ft_key_hook, p);
	mlx_cursor_hook(p->game->mlx, &ft_mouse_move, p);
	mlx_loop(p->game->mlx);
	mlx_delete_image(p->game->mlx, p->game->image);
	mlx_terminate(p->game->mlx);
	ft_ultimate_free(p);

	return (0);
}

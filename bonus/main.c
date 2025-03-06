/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:36:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/11 12:19:41 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_player		*p;
	t_data			data;

	ft_parsing(&data, argc, argv);
	ft_init_png(&data);
	p = ft_define_player(&data);
	ft_define_color_text(p);

	ft_define_cinematic(p);
	mlx_loop_hook(p->game->mlx, ft_ray_casting, p);
	mlx_image_to_window(p->game->mlx, p->game->image, 0, 0);
	mlx_image_to_window(p->game->mlx, p->game->flash, 0, 0);
	mlx_image_to_window(p->game->mlx, p->game->dark, 0, 0);
	mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_HIDDEN);
	mlx_key_hook(p->game->mlx, &ft_key_hook, p);
	mlx_loop(p->game->mlx);
	ft_ultimate_free(p);
	return (0);
}

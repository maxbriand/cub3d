/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:36:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 14:09:00 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_player	*p;
	t_data		data;

	ft_parsing(&data, argc, argv);
	ft_init_png(&data);
	p = ft_define_player(&data);

	p->game->color_north = ft_calloc(sizeof(uint32_t), (p->data->map.t_no_path->height * p->data->map.t_no_path->width) + 1);
	p->game->color_south = ft_calloc(sizeof(uint32_t), (p->data->map.t_so_path->height * p->data->map.t_so_path->width) + 1);
	p->game->color_west = ft_calloc(sizeof(uint32_t), (p->data->map.t_we_path->height * p->data->map.t_we_path->width) + 1);
	p->game->color_east = ft_calloc(sizeof(uint32_t), (p->data->map.t_ea_path->height * p->data->map.t_ea_path->width) + 1);
	//MAYDAY FREE

	int i = 0;
	while (i < p->data->map.t_no_path->height * p->data->map.t_no_path->width)
	{
		p->game->color_north[i] = ((uint8_t)(p->data->map.t_no_path->pixels[i * 4]) << 24) |  // Rouge
		((uint8_t)(p->data->map.t_no_path->pixels[(i * 4) + 1]) << 16) |  // Vert
		((uint8_t)(p->data->map.t_no_path->pixels[(i * 4) + 2]) << 8)  |  // Bleu
		(p->data->map.t_no_path->pixels[(i * 4) + 3]);
		i++;
	}
	i = 0;
	while (i < p->data->map.t_so_path->height * p->data->map.t_so_path->width)
	{
		p->game->color_south[i] = ((uint8_t)(p->data->map.t_so_path->pixels[i * 4]) << 24) |  // Rouge
		((uint8_t)(p->data->map.t_so_path->pixels[(i * 4) + 1]) << 16) |  // Vert
		((uint8_t)(p->data->map.t_so_path->pixels[(i * 4) + 2]) << 8)  |  // Bleu
		(p->data->map.t_so_path->pixels[(i * 4) + 3]);
		i++;
	}
	i = 0;
	while (i < p->data->map.t_we_path->height * p->data->map.t_we_path->width)
	{
		p->game->color_west[i] = ((uint8_t)(p->data->map.t_we_path->pixels[i * 4]) << 24) |  // Rouge
		((uint8_t)(p->data->map.t_we_path->pixels[(i * 4) + 1]) << 16) |  // Vert
		((uint8_t)(p->data->map.t_we_path->pixels[(i * 4) + 2]) << 8)  |  // Bleu
		(p->data->map.t_we_path->pixels[(i * 4) + 3]);
		i++;
	}
	i = 0;
	while (i < p->data->map.t_ea_path->height * p->data->map.t_ea_path->width)
	{
		p->game->color_east[i] = ((uint8_t)(p->data->map.t_ea_path->pixels[i * 4]) << 24) |  // Rouge
		((uint8_t)(p->data->map.t_ea_path->pixels[(i * 4) + 1]) << 16) |  // Vert
		((uint8_t)(p->data->map.t_ea_path->pixels[(i * 4) + 2]) << 8)  |  // Bleu
		(p->data->map.t_ea_path->pixels[(i * 4) + 3]);
		i++;
	}





	//ray casting and print on screen
	mlx_loop_hook(p->game->mlx, ft_ray_casting, p); //map will be in struct set by pars ?
	mlx_image_to_window(p->game->mlx, p->game->image, 0, 0);
	mlx_image_to_window(p->game->mlx, p->game->flash, 0, 0); //change to dark
	mlx_set_cursor_mode(p->game->mlx, MLX_MOUSE_HIDDEN);

	//mlx_key_hook(p->game->mlx, &ft_move_hook, p);
	mlx_key_hook(p->game->mlx, &ft_key_hook, p);
	//mlx_cursor_hook(p->game->mlx, &ft_mouse_move, p);
	mlx_loop(p->game->mlx);
	ft_ultimate_free(p);

	return (0);
}

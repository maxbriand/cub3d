/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:43:01 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/13 16:09:04 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_free_load_png(int i, t_data *data)
{
	if (i == 1)
		mlx_delete_texture(data->map.t_no_path);
	if (i == 2)
	{
		mlx_delete_texture(data->map.t_no_path);
		mlx_delete_texture(data->map.t_so_path);
	}
	if (i == 3)
	{
		mlx_delete_texture(data->map.t_no_path);
		mlx_delete_texture(data->map.t_so_path);
		mlx_delete_texture(data->map.t_ea_path);
	}
	ft_pexit("empty images", data);
}

void	ft_init_png(t_data *data)
{
	data->map.t_no_path = mlx_load_png(data->map.no_path);
	if (!data->map.t_no_path)
		ft_pexit("empty images", data);
	data->map.t_so_path = mlx_load_png(data->map.so_path);
	if (!data->map.t_so_path)
		ft_free_load_png(1, data);
	data->map.t_ea_path = mlx_load_png(data->map.ea_path);
	if (!data->map.t_ea_path)
		ft_free_load_png(2, data);
	data->map.t_we_path = mlx_load_png(data->map.we_path);
	if (!data->map.we_path)
		ft_free_load_png(3, data);
	free(data->map.no_path);
	free(data->map.so_path);
	free(data->map.ea_path);
	free(data->map.we_path);
}

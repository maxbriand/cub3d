/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:43:01 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/13 14:27:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_init_png(t_data *data)
{
	data->map.t_no_path = mlx_load_png(data->map.no_path);
	data->map.t_so_path = mlx_load_png(data->map.so_path);
	data->map.t_ea_path = mlx_load_png(data->map.ea_path);
	data->map.t_we_path = mlx_load_png(data->map.we_path);
	free(data->map.no_path);
	free(data->map.so_path);
	free(data->map.ea_path);
	free(data->map.we_path);
}

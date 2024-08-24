/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:09:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 19:35:01 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_data *data)
{
	data->map.map = NULL;
	data->map.map_copy = NULL;
	data->map.no_path = NULL;
	data->map.so_path = NULL;
	data->map.we_path = NULL;
	data->map.ea_path = NULL;
	data->map.lenmap = -1;
	data->map.floor_r = -1;
	data->map.floor_g = -1;
	data->map.floor_b = -1;
	data->map.ceil_r = -1;
	data->map.ceil_g = -1;
	data->map.ceil_b = -1;
	data->map.len_counter = 0;
	data->x_spoint = -1;
	data->y_spoint = -1;
}

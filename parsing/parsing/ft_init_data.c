/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:09:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/23 03:31:57 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_data(t_data *data)
{
	data->map.map = NULL;
	data->map.no_path = NULL;
	data->map.so_path = NULL;
	data->map.we_path = NULL;
	data->map.ea_path = NULL;
	data->map.floor_r = -1;
	data->map.floor_g = -1;
	data->map.floor_b = -1;
	data->map.ceil_r = -1;
	data->map.ceil_g = -1;
	data->map.ceil_b = -1;
	data->dup.no = 0;
	data->dup.so = 0;
	data->dup.ea = 0;
	data->dup.f = 0;
	data->dup.c = 0;
	data->dup.we = 0;
}
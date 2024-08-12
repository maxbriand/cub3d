/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/12 19:00:57 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_data *data, int ac, char **av)
{
	ft_arg_nbr(ac);
	ft_extension(*(av + 1));
	data->text = ft_get_text(*(av + 1));
	ft_init_data(data);
	ft_catch_ids(data);
	ft_ids_good_path(data);
	ft_map_only_good_char(data, data->map.map);

	// check if all id are set
	printf("%s\n", data->map.map[1]);
	printf("%s\n", data->map.no_path);
	printf("%s\n", data->map.so_path);
	printf("%s\n", data->map.we_path);
	printf("%s\n", data->map.ea_path);
	printf("%d\n", data->map.floor_r);
	printf("%d\n", data->map.floor_g);
	printf("%d\n", data->map.floor_b);
	printf("%d\n", data->map.ceil_r);
	printf("%d\n", data->map.ceil_g);
	printf("%d\n", data->map.ceil_b);
}

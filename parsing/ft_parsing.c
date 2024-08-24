/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 20:02:49 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_data *data, int ac, char **av)
{
	data->text = NULL;
	ft_check_arg_nbr(data, ac);
	ft_check_map_file_extension(data, *(av + 1));
	// alloc text: data->text (free(data->text);)
	data->text = ft_get_text(data, *(av + 1));
	ft_init_data(data);
	// data->text isnt free inside
	// // char	*no_path;
	// char	*so_path;
	// char	*we_path;
	// char	*ea_path;
	// char **map
	// data->map.map: map is malloc + all lines
	ft_cut_text(data);
	ft_check_ids_good_path(data);
	ft_check_map_one_good_char(data, data->map.map);
	ft_check_map_closed(data, data->map.map);
	

	// have to reset to NULL
	free(data->map.no_path);
	free(data->map.so_path);
	free(data->map.ea_path);
	free(data->map.we_path);
	ft_arrfree(data->map.map);
}

	// check if all id are set
	// printf("%s\n", data->map.no_path);
	// printf("%s\n", data->map.so_path);
	// printf("%s\n", data->map.we_path);
	// printf("%s\n", data->map.ea_path);
	// printf("%d\n", data->map.floor_r);
	// printf("%d\n", data->map.floor_g);
	// printf("%d\n", data->map.floor_b);
	// printf("%d\n", data->map.ceil_r);
	// printf("%d\n", data->map.ceil_g);
	// printf("%d\n", data->map.ceil_b);

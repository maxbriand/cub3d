/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/25 01:05:42 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// have to reset to NULL
void	ft_parsing(t_data *data, int ac, char **av)
{
	data->text = NULL;
	ft_check_arg_nbr(data, ac);
	ft_check_map_file_extension(data, *(av + 1));
	data->text = ft_get_text(data, *(av + 1));
	ft_init_data(data);
	ft_cut_text(data);
	ft_check_ids_good_path(data);
	ft_check_map_one_good_char(data, data->map.map);
	ft_check_map_closed(data, data->map.map);
	free(data->map.no_path);
	free(data->map.so_path);
	free(data->map.ea_path);
	free(data->map.we_path);
	ft_arrfree(data->map.map);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/13 17:09:34 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_parsing(t_data *data, int ac, char **av)
{
	ft_init_data(data);
	ft_check_arg_nbr(data, ac);
	ft_check_map_file_extension(data, *(av + 1));
	data->text = ft_get_text(data, *(av + 1));
	ft_cut_text(data);
	ft_check_ids_good_path(data);
	ft_check_map_size(data, data->map.map);
	ft_check_map_one_good_char(data, data->map.map);
	ft_check_map_closed(data, data->map.map);
}

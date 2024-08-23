/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ids_good_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:27:40 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/23 16:24:43 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ids_good_path(t_data *data)
{
	int	fd;

	fd = open(data->map.no_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("north texture path doesn't exists", data);
	fd = open(data->map.so_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("south texture path doesn't exists", data);
	fd = open(data->map.we_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("west texture path doesn't exists", data);
	fd = open(data->map.ea_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("east texture path doesn't exists", data);
}

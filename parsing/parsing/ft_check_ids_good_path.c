/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ids_good_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:27:40 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/26 00:15:46 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_ids_good_path(t_data *data)
{
	int	fd;

	fd = open(data->map.no_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("north texture path doesn't exists", data);
	close(fd);
	fd = open(data->map.so_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("south texture path doesn't exists", data);
	close(fd);
	fd = open(data->map.we_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("west texture path doesn't exists", data);
	close(fd);
	fd = open(data->map.ea_path, O_RDONLY);
	if (fd == -1)
		ft_pexit("east texture path doesn't exists", data);
	close(fd);
}

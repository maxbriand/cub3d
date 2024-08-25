/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:01:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/26 00:17:54 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_floodfill(t_data *data, char **map, int y, int x)
{
	if (y < 0 || x < 0)
		ft_pexit("map not closed by walls", data);
	if (y >= data->map.height_map || x >= (int) ft_strlen(map[y]))
		ft_pexit("map not closed by walls", data);
	if (map[y][x] == '1')
		return ;
	else
		map[y][x] = '1';
	ft_floodfill(data, map, y - 1, x);
	ft_floodfill(data, map, y, x + 1);
	ft_floodfill(data, map, y + 1, x);
	ft_floodfill(data, map, y, x - 1);
}

// malloc data->map.map_copy and free
void	ft_check_map_closed(t_data *data, char **map)
{
	data->map.map_copy = malloc(sizeof(char *) * (data->map.height_map + 1));
	if (!data->map.map_copy)
		ft_pexit("malloc issue", data);
	ft_arrcpy(data->map.map_copy, map);
	ft_floodfill(data, data->map.map_copy, data->y_spoint, data->x_spoint);
	ft_arrfree(data->map.map_copy);
	data->map.map_copy = NULL;
}

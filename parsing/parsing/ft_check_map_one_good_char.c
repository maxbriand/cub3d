/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_one_good_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:54:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/07 22:32:52 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_only_one_spawn(char **map, int i, int j, t_data *data)
{
	if (data->x_spoint != -1)
		ft_pexit("two spawning points", data);
	data->map.spawning_orientation = map[i][j];
	data->x_spoint = j;
	data->y_spoint = i;
}

void	ft_check_map_one_good_char(t_data *data, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && \
				map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E' && \
				!ft_isspace(map[i][j]))
				ft_pexit("map contains an impossible character", data);
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
				ft_only_one_spawn(map, i, j, data);
			j++;
		}
		j = 0;
		i++;
	}
	if (data->x_spoint == -1)
		ft_pexit("map doesn't contains spawning point", data);
}

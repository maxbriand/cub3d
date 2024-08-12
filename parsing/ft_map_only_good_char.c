/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_only_good_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:54:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/12 18:53:22 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_only_good_char(t_data *data)
{
	int		i;
	int		j;
	bool	spawn;

	i = 0;
	j = 0;
	spawn = 0;
	while(data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0' && \
				data->map.map[i][j] != 'N' && data->map.map[i][j] != 'S' && \
				data->map.map[i][j] != 'W' && data->map.map[i][j] != 'E' && \
				!ft_isspace(data->map.map[i][j]))
				ft_pexit("map contains an impossible char", data);
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S' || \
				data->map.map[i][j] == 'W' || data->map.map[i][j] == 'E')
				spawn = 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (!spawn)
		ft_pexit("map doesn't contains spawning point", data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_only_good_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:54:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/12 23:29:20 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_only_one_spawn(t_data *data, bool *spawn)
{
	if (*spawn)
		ft_pexit("two spawning points", data);
	*spawn = 1;
}

void	ft_map_only_good_char(t_data *data, char **map)
{
	int		i;
	int		j;
	bool	spawn;

	i = 0;
	j = 0;
	spawn = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && \
				map[i][j] != 'S' && map[i][j] != 'W' && map[i][j] != 'E' && \
				!ft_isspace(map[i][j]))
				ft_pexit("map contains an impossible char", data);
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
				ft_only_one_spawn(data, &spawn);
			j++;
		}
		j = 0;
		i++;
	}
	if (!spawn)
		ft_pexit("map doesn't contains spawning point", data);
}

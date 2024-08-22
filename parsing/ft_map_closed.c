/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:01:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/22 18:18:30 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_closed_right(t_data *data, char **map)
{
	char	last_char;
	int		i;

	i = 0;
	while (*map)
	{
		ft_printf("the string is: %s\n", *map);
		while (*map[i] != '1')
		{
			printf("Ok");
			if (!ft_isspace(*map[i]))
				last_char = *map[i];
			i++;
		}
		// if (last_char != '1')
		// 	ft_pexit("right side of the map isn't closed", data);
		i = 0;
		map++;	
	}
}

static void	ft_closed_left(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		while (ft_isspace(*map[i]))
			i++;
		if (*map[i] != '1')
			ft_pexit("left side of the map isn't closed", data);
		i = 0;
		map++;
	}

}

void	ft_map_closed(t_data *data, char **map)
{
	ft_closed_left(data, map);
	ft_closed_right(data, map);
	printf("right side is closed\n");
}

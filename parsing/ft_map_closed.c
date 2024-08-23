/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:01:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/23 17:20:43 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	ft_arrlongest()
// {



// }

// static void	ft_top_closed(t_data *data, char **map)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	bool	map_started;

// 	i = -1;
// 	j = 0;
// 	map_started = 0;
// 	len = ft_arrlen(map);
// 	while (1)
// 	{
// 		while (map[i++])
// 		{
// 			if (j + 1 > ft_strlen(map[i]))
// 				continue ;
// 			if (!ft_isspace(map[i][j]))
// 				break ;
// 		}
// 		if (map[i][j] == '1')
// 			map_started = 1;
// 		else if (!map[i][j] && map_started)
			
// 		i = 0;
// 		j++;
// 	}
// }

// static void	ft_right_closed(t_data *data, char **map)
// {
// 	char	last_char;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	map++;
// 	while (map[i])
// 	{
// 		while (map[i][j] != '\0')
// 		{
// 			if (!ft_isspace(map[i][j]))
// 				last_char = map[i][j];
// 			j++;
// 		}
// 		if (last_char != '1')
// 			ft_pexit("right side of the map isn't closed", data);
// 		j = 0;
// 		i++;
// 	}
// }

// static void	ft_left_closed(t_data *data, char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (map[i])
// 	{
// 		while (ft_isspace(map[i][j]))
// 			j++;
// 		if (map[i][j] != '1')
// 			ft_pexit("left side of the map isn't closed", data);
// 		j = 0;
// 		i++;
// 	}

// }

// void	ft_map_closed(t_data *data, char **map)
// {
// 	// ft_left_closed(data, map);
// 	// ft_right_closed(data, map);
// 	// ft_top_closed(data, map);
// 	printf("top side is closed\n");
// }


	// data->x_spoint, data->y_spoint;
void	ft_map_closed(t_data *data, char **map, int y, int x)
{
	// check 

	if (map[y][x] == '0')
		

	ft_map_closed(data, map, y - 1, x);
	ft_map_closed(data, map, y, x + 1);
	ft_map_closed(data, map, y + 1, x);
	ft_map_closed(data, map, y, x - 1);
}


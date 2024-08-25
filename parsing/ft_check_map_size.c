/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:12:31 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/26 00:31:02 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_size(t_data *data, char **map)
{
	if (!map)
		ft_pexit("no map detected", data);
	data->map.height_map = ft_arrlen(map);
	if (data->map.height_map > 200)
		ft_pexit("the map height should be max 200", data);
	while (*map)
	{
		if ((int) ft_strlen(*map) > 200)
			ft_pexit("the map lenght should be max 200", data);
		map++;
	}
}

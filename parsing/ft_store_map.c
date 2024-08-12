/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:31:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/13 01:00:23 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_counter_no_empty_line(char **map)
{
	int		i;
	int		j;
	char	c;	

	i = 0;
	j = 0;
	c = '\0';
	while (map[i])
	{
		while (map[i][j])
		{
			if (!ft_isspace(c))
			{
				c = map[i][j];
				break ;
			}
			j++;
		}		
		if (!c)
			break ;
		c = '\0';
		j = 0;
		i++;
	}
	return (i);
}

static void	ft_remove_empty_line(t_data *data, char **map)
{
	int		n;
	char	**clean_map;

	n = ft_counter_no_empty_line(map);
	clean_map = malloc(sizeof(char *) * (n + 1));
	if (!clean_map)
		ft_pexit("malloc issue", data);
	data->map.map = ft_arrncpy(clean_map, map, n);
	ft_arrfree(map);
}

void	ft_store_map(t_data *data, char *text)
{
	char	*c_line;

	c_line = text;
	while (*text)
	{
		while (ft_isspace(*text) && *text != '\n')
			text++;
		if (*text == '\n')
			c_line = text;
		else if (!*text)
			break ;
		else
		{
			data->map.map = ft_split(c_line, '\n');
			// ft_remove_empty_line(data, data->map.map);
			return ;
		}
		text++;
	}
}

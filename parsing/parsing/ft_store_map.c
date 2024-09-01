/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:31:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/26 00:26:29 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_add_map_line(t_data *data, char **map, char *text, char *start_line)
{
	*map = malloc(sizeof(char) * (text - start_line + 1));
	if (!*map)
		ft_pexit("malloc issue", data);
	ft_strlcpy(*map, start_line, text - start_line + 1);
}

// add an extra space in case of nothing after \n 
char	**ft_new_split(t_data *data, char *text, char c)
{
	char	**map;
	char	*start_line;
	char	**save_map;

	map = malloc(sizeof(char *) * (ft_count_char(text, c) + 2));
	if (!map)
		ft_pexit("malloc issue", data);
	save_map = map;
	while (*text)
	{
		start_line = text;
		while (*text != c && *text)
			text++;
		ft_add_map_line(data, map, text, start_line);
		map++;
		if (!*text)
			break ;
		text++;
	}
	*map = NULL;
	return (save_map);
}

// remove the first empty line
void	ft_store_map(t_data *data, char *text)
{
	char	*c_line;

	c_line = text;
	while (*text)
	{
		while (ft_isspace(*text) && *text != '\n')
			text++;
		if (*text == '\n')
			c_line = text + 1;
		else if (!*text)
			break ;
		else
		{
			data->map.map = ft_new_split(data, c_line, '\n');
			free(data->text);
			data->text = NULL;
			return ;
		}
		text++;
	}
}

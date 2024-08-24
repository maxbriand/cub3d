/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:31:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/25 01:05:55 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// add an extra space in case of nothing after \n 
char	**ft_new_split(t_data *data, char *text, char c)
{
	char	**map;
	char	*start_line;
	int		len_line;
	char	**save_map;

	map = malloc(sizeof(char *) * (ft_count_char(text, c) + 2));
	if (!map)
		ft_pexit("malloc issue", data);
	save_map = map;
	while (*text)
	{
		start_line = text;
		while (*text != '\n' && *text)
			text++;
		len_line = text - start_line;
		*map = malloc(sizeof(char) * (text - start_line + 1));
		if (!map)
			ft_pexit("malloc issue", data);
		ft_strlcpy(*map, start_line, len_line + 1);
		if (*text)
			break ;
		map++;
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

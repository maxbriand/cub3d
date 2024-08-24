/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:31:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 19:11:03 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	ft_counter_no_empty_line(char **map)
// {
// 	int		i;
// 	int		j;
// 	char	c;	

// 	i = 0;
// 	j = 0;
// 	c = '\0';
// 	while (map[i])
// 	{
// 		while (map[i][j])
// 		{
// 			if (!ft_isspace(c))
// 			{
// 				c = map[i][j];
// 				break ;
// 			}
// 			j++;
// 		}		
// 		if (!c)
// 			break ;
// 		c = '\0';
// 		j = 0;
// 		i++;
// 	}
// 	return (i);
// }

// static void	ft_remove_empty_line(t_data *data, char **map)
// {
// 	int		n;
// 	char	**clean_map;

// 	n = ft_counter_no_empty_line(map);
// 	clean_map = malloc(sizeof(char *) * (n + 1));
// 	if (!clean_map)
// 		ft_pexit("malloc issue", data);
// 	data->map.map = ft_arrncpy(clean_map, map, n);
// 	ft_arrfree(map);
// }

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:37:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/26 00:27:53 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_shorter_atol_color(int d, char c)
{
	if (d == 1 && c == ',')
		return (1);
	if (d == 2 && ft_isspace(c))
		return (1);
	return (0);
}

int	ft_atol_color(t_data *data, char *text, int d)
{
	long	color;
	char	*number;
	int		i;

	if (!text)
		ft_pexit("missing information on the map", data);
	i = 0;
	while (text[i])
	{
		if (ft_shorter_atol_color(d, text[i]))
			break ;
		if (!ft_isdigit(text[i]))
			ft_pexit("isn't a correct number", data);
		i++;
	}
	data->map.len_counter = i + 1;
	number = malloc(i + 1);
	if (!number)
		ft_pexit("malloc issue", data);
	ft_strlcpy(number, text, i + 1);
	color = ft_atol(number);
	free(number);
	if (color < 0 || color > 255)
		ft_pexit("one rgb code isn't in a good scope", data);
	return (color);
}

int	ft_set_color(t_data *data, char *text, int nbr)
{
	int	len;

	len = 0;
	if (nbr == 4)
	{
		data->map.floor_r = ft_atol_color(data, text, 1);
		len = data->map.len_counter;
		data->map.floor_g = ft_atol_color(data, text + len, 1);
		len += data->map.len_counter;
		data->map.floor_b = ft_atol_color(data, text + len, 2);
		len += data->map.len_counter;
	}
	else if (nbr == 5)
	{
		data->map.ceil_r = ft_atol_color(data, text, 1);
		len = data->map.len_counter;
		data->map.ceil_g = ft_atol_color(data, text + len, 1);
		len += data->map.len_counter;
		data->map.ceil_b = ft_atol_color(data, text + len, 2);
		len += data->map.len_counter;
	}
	return (len - 1);
}

// char	*no_path;
// char	*so_path;
// char	*we_path;
// char	*ea_path;
int	ft_set_orientation(t_data *data, char *text, int nbr)
{
	int		len;
	char	*info;

	len = 0;
	while (ft_isprint(text[len]) && text[len] != ' ')
		len++;
	info = malloc(len + 1);
	if (!info)
		ft_pexit("malloc issue", data);
	ft_strlcpy(info, text, len + 1);
	if (nbr == 0)
		data->map.no_path = info;
	if (nbr == 1)
		data->map.so_path = info;
	if (nbr == 2)
		data->map.we_path = info;
	if (nbr == 3)
		data->map.ea_path = info;
	return (len);
}

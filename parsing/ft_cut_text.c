/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:28:27 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 20:22:50 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atol_color(t_data *data, char *text, int d)
{
	long	color;
	char	*number;
	int		i;

	if (!text)
		ft_pexit("missing information on the map", data);
	i = 0;
	while (text[i])
	{
		if (d == 1 && text[i] == ',')
			break ;
		if (d == 2 && ft_isspace(text[i]))
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

static int ft_set_color(t_data *data, char *text, int nbr)
{
	int	len;

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

static void	ft_id_already_set(t_data *data, int nbr)
{
	if (nbr == 0)
	{
		if (data->map.no_path)
			ft_pexit("duplicate NO id", data);
	}
	if (nbr == 1)
	{
		if (data->map.so_path)
			ft_pexit("duplicate SO id", data);
	}
	if (nbr == 2)
	{
		if (data->map.we_path)
			ft_pexit("duplicate WE id", data);
	}
	if (nbr == 3)
	{
		if (data->map.ea_path)
			ft_pexit("duplicate EA id", data);
	}
	if (nbr == 4)
	{
		if (data->map.floor_r != -1)
			ft_pexit("duplicate F id", data);
	}
	if (nbr == 5)
	{
		if (data->map.ceil_r != -1)
			ft_pexit("duplicate C id", data);
	}
}

// char	*no_path;
// char	*so_path;
// char	*we_path;
// char	*ea_path;
static int ft_set_orientation(t_data *data, char *text, int nbr)
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

// identify ID
int	ft_identify_id(t_data *data, char *text, int *counter)
{
	const char	*ids[] = {"NO", "SO", "WE", "EA", "F", "C", "\0"};
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (ids[nbr])
	{
		if (nbr >= 6)
			ft_pexit("unknows identifier", data);
		if (!ft_strncmp(ids[nbr], text, ft_strlen(ids[nbr])))
			break ;
		nbr++;
	}
	ft_id_already_set(data, nbr);
	i += ft_strlen(ids[nbr]);
	if (!ft_isspace(text[i]))
		ft_pexit("unknows identifier", data);
	while (ft_isspace(text[i]))
		i++;
	if (ft_strlen(ids[nbr]) == 2)
		i += ft_set_orientation(data, text + i, nbr);
	else
		i += ft_set_color(data, text + i, nbr);
	*counter += 1;
	return (i);
}

// iterate line by line until counter = 6 or end of text
// malloc map
void	ft_cut_text(t_data *data)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (data->text[i])
	{
		while (ft_isspace(data->text[i]))
			i++;
		if (!data->text[i])
			break ;
		if (counter < 6)
			i += ft_identify_id(data, data->text + i, &counter);
		if (counter == 6)
			return (ft_store_map(data, data->text + i));
		i++;
	}
	if (counter < 6)
		ft_pexit("some identifiers are missing", data);
}

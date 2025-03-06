/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:28:27 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/25 19:38:48 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_id_already_set2(t_data *data, int nbr)
{
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
	ft_id_already_set2(data, nbr);
}

int	ft_select_id(t_data *data, char *text)
{
	const char	*ids[] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			nbr;

	nbr = 0;
	while (1)
	{
		if (nbr >= 6)
			ft_pexit("unknows identifier", data);
		if (!ft_strncmp(ids[nbr], text, ft_strlen(ids[nbr])))
			break ;
		nbr++;
	}
	return (nbr);
}

// identify ID
int	ft_identify_id(t_data *data, char *text, int *counter)
{
	const char	*ids[] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	int			nbr;

	i = 0;
	nbr = ft_select_id(data, text);
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
	if (!data->text)
		ft_pexit("empty file", data);
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

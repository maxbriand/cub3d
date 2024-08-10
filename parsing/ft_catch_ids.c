/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_ids.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:28:27 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/08 00:56:25 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// static int ft_set_color(char *text)
	// {
	// 	// int	j;


	// }


	// static int ft_set_orientation(char *text)
	// {
	// 	if ()


	// }

// identify ID
int	ft_identify_id(t_data *data, char *text)
{
	const char	*ids[] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (ids[i])
	{
		if (!ft_strcmp(ids[i], text))
			break ;
		i++;
	}
	if (i >= 6)
		ft_pexit("unknows identifier", data);
	while (!ft_isspace(text[j]))
		j++;
	while (ft_isspace(text[j]))
		j++;
	if (i <= 3)
		j += ft_set_orientation(text[j]);
	else
		j += ft_set_color(text[j]);
	return (j);
}

// iterate line by line until counter = 6 or end of text
void	ft_catch_ids(t_data *data)
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
			break;
		i += ft_store_id();

		if (counter < 6)
			ft_handle_line(data, data->text + i, &counter);
		i++;
	}
	if (counter < 6)
		ft_pexit("some identifiers are missing", data);
}

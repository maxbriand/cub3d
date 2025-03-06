/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:17:43 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/25 18:39:23 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_struct(t_data *data)
{
	if (data->text)
		free(data->text);
	if (data->map.map)
		ft_arrfree(data->map.map);
	if (data->map.map_copy)
		ft_arrfree(data->map.map_copy);
	if (data->map.ea_path)
		free(data->map.ea_path);
	if (data->map.so_path)
		free(data->map.so_path);
	if (data->map.no_path)
		free(data->map.no_path);
	if (data->map.we_path)
		free(data->map.we_path);
}

void	ft_pexit(char *msg, t_data *data)
{
	ft_free_struct(data);
	write(2, "Error\n", 6);
	write(2, "cub3d: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit (1);
}

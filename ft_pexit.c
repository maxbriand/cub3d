/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:17:43 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/07 00:32:43 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pexit(char *msg, t_data *data)
{
	write(2, "Error\n", 6);
	write(2, "cub3d: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (data->text)
		free(data->text);
	exit (1);
}

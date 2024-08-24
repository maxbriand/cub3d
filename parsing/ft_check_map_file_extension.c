/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file_extension.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:13:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 19:58:07 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_file_extension(t_data *data, char *path)
{
	int	l;

	l = ft_strlen(path);
	if (path[l - 1] != 'b' || path[l - 2] != 'u' || path[l - 3] != 'c' || \
		path[l - 4] != '.')
		ft_pexit("the file extension isn't correct", data);
}

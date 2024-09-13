/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file_extension.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:13:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/13 15:44:18 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_check_map_file_extension(t_data *data, char *path)
{
	int	l;

	l = ft_strlen(path);
	if (path[l - 1] != 'b' || path[l - 2] != 'u' || path[l - 3] != 'c' || \
		path[l - 4] != '.')
		ft_pexit("the file extension isn't correct", data);
    if (l == 4 || path[l - 5] == '/')
        ft_pexit(".cub is a hidden file", data);
}

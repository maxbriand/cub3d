/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:13:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/12 18:55:57 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_extension(char *path)
{
	int	l;

	l = ft_strlen(path);
	if (path[l - 1] != 'b' || path[l - 2] != 'u' || path[l - 3] != 'c' || \
		path[l - 4] != '.')
		ft_pexit("the file extension isn't correct", NULL);
}

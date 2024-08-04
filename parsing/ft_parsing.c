/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/04 21:31:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(int ac, char **av)
{
	char	*map;
	char	*path;

	path = *(av+1);

	ft_arg_nbr(ac);
	ft_extension(*(av+1));
	text = ft_get_text(path);

}

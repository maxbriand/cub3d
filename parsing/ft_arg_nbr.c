/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:14:39 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/06 18:01:19 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_arg_nbr(int ac)
{
	if (ac < 2)
		ft_pexit("too few arguments", NULL);
	if (ac > 2)
		ft_pexit("too many arguments", NULL);
}

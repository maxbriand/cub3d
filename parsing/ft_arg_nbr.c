/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:14:39 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/02 01:21:27 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_arg_nbr(int ac)
{
	if (ac < 2)
		ft_pexit("cub3d: too few arguments");
	if (ac > 2)
		ft_pexit("cub3d: too many arguments");
}

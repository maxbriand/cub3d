/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:14:39 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 19:57:38 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_arg_nbr(t_data *data, int ac)
{
	if (ac < 2)
		ft_pexit("too few arguments", data);
	if (ac > 2)
		ft_pexit("too many arguments", data);
}

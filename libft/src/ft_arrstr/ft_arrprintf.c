/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:20:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/13 01:00:02 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrprintf(char **arr_of_str)
{
	int	i;

	if (!arr_of_str)
		return ;
	i = 0;
	while (arr_of_str[i])
	{
		if (!arr_of_str[i + 1])
			ft_printf("%s\n", arr_of_str[i]);
		else
			ft_printf("%s\n", arr_of_str[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:20:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/06/03 18:46:17 by mbriand          ###   ########.fr       */
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
			ft_printf("%s", arr_of_str[i]);
		else
			ft_printf("%s ", arr_of_str[i]);
		i++;
	}
}

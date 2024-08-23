/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:22:52 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/23 17:02:45 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// We don't need to free the NULL pointer because it's not malloc

void	ft_arrfree(char **str_array)
{
	char	**save_str_array;

	if (str_array == 0)
		return ;
	save_str_array = str_array;
	while (*str_array)
	{
		free(*str_array);
		str_array++;
	}
	free(save_str_array);
}

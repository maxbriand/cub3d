/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:53:15 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/23 17:11:19 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return 0 = malloc error
// if fail during the process the new_array / 
	//beginning of the new array is free
char	**ft_arrcat(char **array, char *str)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = malloc(sizeof(char *) * (ft_arrlen(array) + 1));
	if (new_array == NULL)
		return (0);
	while (array[i])
	{
		new_array[i] = ft_strjoin(array[i], str);
		if (new_array[i] == NULL)
		{
			ft_arrfree(new_array);
			return (0);
		}
		i++;
	}
	new_array[i] = array[i];
	return (new_array);
}

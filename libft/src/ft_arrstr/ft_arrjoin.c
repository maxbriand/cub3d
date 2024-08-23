/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:31:24 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/23 17:33:47 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// join the old_array with joined_array
static int	ft_add_array(char **joined_array, char **old_array, int i)
{
	int	j;

	if (old_array == NULL)
		return (i);
	j = 0;
	while (old_array[j] != NULL)
	{
		joined_array[i] = old_array[j];
		i++;
		j++;
	}
	free(old_array);
	return (i);
}

// join two array of str
char	**ft_arrjoin(char **fst_array, char **snd_array)
{
	char	**joined_array;
	int		counter;
	int		i;

	counter = ft_arrlen(fst_array) + ft_arrlen(snd_array) + 1;
	joined_array = malloc(sizeof(char *) * counter);
	if (joined_array == NULL)
		return (NULL);
	i = 0;
	i = ft_add_array(joined_array, fst_array, i);
	i = ft_add_array(joined_array, snd_array, i);
	joined_array[i] = NULL;
	return (joined_array);
}

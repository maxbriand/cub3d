/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addback_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:11:13 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:30:16 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//add 1 element to a array. Free old array, so not needed to free it after
char	**ft_addback_array(char **old_array, char *new_element)
{
	char	**new_array;
	int		i;
	int		len;

	len = ft_strlen_array(old_array);
	new_array = ft_calloc((len + 2), sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	if (old_array)
	{
		while (old_array[i])
		{
			new_array[i] = ft_strdup(old_array[i]);
			if (!new_array[i])
				return (NULL);
			i++;
		}
		ft_free_array(old_array);
	}
	new_array[i] = ft_strdup(new_element);
	if (!new_array[i])
		return (NULL);
	new_array[i + 1] = NULL;
	return (new_array);
}

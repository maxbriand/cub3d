/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addback_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:14:47 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:14:48 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//addback for array of int
int	*ft_addback_int(int *old_array, int new_element)
{
	int	*new_array;
	int	i;

	i = 0;
	if (old_array)
	{
		while (old_array[i] != -1)
			i++;
	}
	new_array = malloc(sizeof(int) * (i + 2));
	if (!new_array)
		return (NULL);
	if (old_array)
	{
		i = 0;
		while (old_array[i] != -1)
		{
			new_array[i] = old_array[i];
			i++;
		}
		free(old_array);
	}
	new_array[i] = new_element;
	new_array[i + 1] = -1;
	return (new_array);
}

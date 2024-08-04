/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addback_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:16:29 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:44:50 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//addback for a string. Need to send &str (str is a char*)
char	*ft_charaddback(char **old_array, char new_element)
{
	char	*new_array;
	int		i;
	int		len;

	len = ft_better_strlen(*old_array);
	if (new_element == '\0' && !*old_array)
		new_array = malloc(sizeof(char));
	else
		new_array = malloc(sizeof(char) * (len + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	if ((*old_array))
	{
		while ((*old_array)[i])
		{
			new_array[i] = (*old_array)[i];
			i++;
		}
		free(*old_array);
	}
	new_array[i] = new_element;
	if (new_element != '\0')
		new_array[i + 1] = '\0';
	return (new_array);
}

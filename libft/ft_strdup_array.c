/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:21:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:30:44 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//strdup but for an array.
char	**ft_strdup_array(char **array)
{
	char	**result;
	int		i;

	if (!array)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char *) * (ft_strlen_array(array) + 1));
	if (!result)
	{
		array = NULL;
		return (NULL);
	}
	while (array[i])
	{
		result[i] = ft_strdup(array[i]);
		if (!result[i])
		{
			ft_free_array(result);
			result = NULL;
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

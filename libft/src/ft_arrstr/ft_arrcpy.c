/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:57:38 by mbriand           #+#    #+#             */
/*   Updated: 2024/06/03 19:00:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// malloc use - cpy string by string from src to dest (alloc array)
char	**ft_arrcpy(char **dest, char **src)
{
	char	**store_dest;

	store_dest = dest;
	if (!src || !dest)
		return (NULL);
	while (*src)
	{
		*dest = ft_strdup(*src);
		dest++;
		src++;
	}
	*dest = NULL;
	return (store_dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:47:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/06/03 19:07:24 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// malloc use - cpy n string of src
char	**ft_arrncpy(char **dest, char **src, int n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

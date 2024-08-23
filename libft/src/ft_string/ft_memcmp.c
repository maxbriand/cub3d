/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:49:34 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/30 17:46:57 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compare pointer in memory
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cp;
	unsigned char	*s2cp;

	s1cp = (unsigned char *) s1;
	s2cp = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*(s1cp + i) != *(s2cp + i))
			return (*(s1cp + i) - *(s2cp + i));
		i++;
	}
	return (0);
}

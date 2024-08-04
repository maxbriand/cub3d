/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:37:00 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/02 17:33:40 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		f;
	char		*dest2;
	char		*src2;

	dest2 = dest;
	src2 = (char *)src;
	f = 0;
	if (n && ((src || dest)))
	{
		while (f < n)
		{
			dest2[f] = src2[f];
			f++;
		}
	}
	return (dest);
}

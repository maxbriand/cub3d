/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:13:21 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/03 19:53:54 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		f;
	int		a;
	size_t	b;

	f = 0;
	a = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	i = ft_strlen(dest) + ft_strlen(src);
	while (dest[f] != '\0')
		f++;
	b = ft_strlen(dest);
	while (src[a] != '\0' && b + a < (size - 1))
	{
		dest[f] = src[a];
		f++;
		a++;
	}
	dest[f] = '\0';
	return (i);
}

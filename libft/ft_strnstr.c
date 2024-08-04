/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:06:56 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/02 17:07:56 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	b;
	size_t	f;

	i = 0;
	if (little[0] == '\0')
		return ((char *)&big[0]);
	while (i != len && big[i] != '\0')
	{
		f = 0;
		if (big[i] == little[f])
		{
			b = i;
			while (big[i] == little[f] && i < len)
			{
				if (little[f + 1] == '\0')
					return ((char *)&big[b]);
				i++;
				f++;
			}
			i = b;
		}
		i++;
	}
	return (0);
}

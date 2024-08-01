/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:18:57 by mbriand           #+#    #+#             */
/*   Updated: 2023/11/27 19:18:13 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total;
	void		*str;

	if (nmemb != 0 && size != 0)
	{
		if (size > 2147483647 / nmemb)
			return (NULL);
	}
	total = nmemb * size;
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, total);
	return (str);
}

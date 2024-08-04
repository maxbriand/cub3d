/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:52:22 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/05 14:52:25 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long int	size_alloc;
	void		*mem_al;

	size_alloc = nmemb * size;
	if (size_alloc < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	mem_al = malloc(size_alloc);
	if (mem_al)
		ft_memset(mem_al, 0, size_alloc);
	return (mem_al);
}

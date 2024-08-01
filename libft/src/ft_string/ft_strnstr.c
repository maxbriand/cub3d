/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:45:44 by mbriand           #+#    #+#             */
/*   Updated: 2023/11/27 20:54:35 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strnstr = search 1st str in small str on each number n
// stop at null terminated, null terminated is not search 

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_b;
	size_t	i_b_loop;
	size_t	i_l;

	i_b = 0;
	i_l = 0;
	i_b_loop = 0;
	if (little[i_b] == '\0')
		return ((char *) big);
	while (big[i_b] && i_b < len)
	{
		while (big[i_b_loop] == little[i_l] && i_b_loop < len && little[i_l])
		{
			i_l++;
			i_b_loop++;
		}
		if (little[i_l] == '\0')
			return ((char *) big + (i_b_loop - i_l));
		i_l = 0;
		i_b++;
		i_b_loop = i_b;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:53:03 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/01 15:13:58 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*pt_s1;
	const unsigned char	*pt_s2;

	pt_s1 = (const unsigned char *)s1;
	pt_s2 = (const unsigned char *)s2;
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
	{
		if (n == 0)
			return (0);
		else
			return (*pt_s1 - *pt_s2);
	}
	if (*pt_s1 == '\0' || *pt_s2 == '\0')
		return (*pt_s1 - *pt_s2);
	while (n > 0 && *pt_s1 != '\0')
	{
		if (*pt_s1 != *pt_s2)
			return (*pt_s1 - *pt_s2);
		pt_s1++;
		pt_s2++;
		n--;
	}
	if (*pt_s1 != *pt_s2 && n > 0)
		return (*pt_s1 - *pt_s2);
	return (0);
}

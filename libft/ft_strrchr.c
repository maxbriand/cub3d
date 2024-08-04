/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:15:05 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/01 14:46:35 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pt;

	c %= 128;
	if (ft_isascii(c) == 0)
	{
		pt = (char *)&s[0];
		return (pt);
	}
	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == c)
		{
			pt = (char *) &s[i];
			return (pt);
		}
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:21:22 by mbriand           #+#    #+#             */
/*   Updated: 2023/11/27 19:18:43 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n >= 1 || n <= -1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*recursive(char *pt, int n)
{
	if (n == -2147483648)
	{
		ft_strlcpy(pt, "-2147483648", 12);
		return (pt);
	}
	if (n < 0)
	{
		pt[0] = '-';
		recursive(pt + 1, n *= -1);
		n = 0;
	}
	if (n >= 10)
	{
		pt = recursive(pt, n / 10);
		pt[0] = (n % 10) + 48;
	}
	if (n > 0)
		pt[0] = (n % 10) + 48;
	return (pt + 1);
}

char	*ft_itoa(int n)
{
	char	*pt;
	int		lenght;

	lenght = digit_counter(n);
	pt = malloc(sizeof(char) * digit_counter(n) + 1);
	if (!pt)
		return (NULL);
	if (n == 0)
	{
		ft_strlcpy(pt, "0\0", 2);
		return (pt);
	}
	recursive(pt, n);
	pt[lenght] = '\0';
	return (pt);
}

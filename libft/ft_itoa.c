/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:26:08 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/17 17:53:18 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_number(int n, int *negatif)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		c++;
		*negatif = 1;
	}
	while (n)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static char	*ft_swap(char *str, int negatif)
{
	char	b;
	int		a;
	int		z;

	a = 0;
	if (negatif)
		a++;
	z = ft_strlen(str);
	z--;
	while (a < z)
	{
		b = str[a];
		str[a] = str[z];
		str[z] = b;
		a++;
		z--;
	}
	return (str);
}

static char	*write_str2(char *str, int n, int negatif)
{
	int	i;

	i = 0;
	if (negatif)
	{
		str[i] = '-';
		i++;
	}
	while (n > 9)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	str[i] = (n % 10) + 48;
	i++;
	str[i] = '\0';
	str = ft_swap(str, negatif);
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	c;
	char	*str;
	int		negatif;

	negatif = 0;
	c = count_number(n, &negatif);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = n * (-1);
	str = malloc(sizeof(char) * c + 1);
	if (!str)
		return (NULL);
	str = write_str2(str, n, negatif);
	return (str);
}

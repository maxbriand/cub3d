/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:04:34 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/11 17:19:11 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_handle_sign(const char *sign, long nbr)
{
	if (*sign == '-')
		nbr *= -1;
	return (nbr);
}

long	ft_atol(const char *s)
{
	long		nbr;
	const char	*sign;
	int			digit;	

	nbr = 0;
	while (ft_isspace(*s) == 1)
		s++;
	sign = s;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		digit = *s - '0';
		if ((((LONG_MAX / 10 == nbr) && digit > LONG_MAX % 10)
				|| (LONG_MAX / 10 < nbr)) && *sign != '-')
			return (LONG_MAX);
		if ((((LONG_MIN / 10 == -nbr) && - digit < LONG_MIN % 10)
				|| (LONG_MIN / 10 > -nbr)) && *sign == '-')
			return (LONG_MIN);
		nbr *= 10;
		nbr += (*s) - 48;
		s++;
	}
	nbr = ft_handle_sign(sign, nbr);
	return (nbr);
}

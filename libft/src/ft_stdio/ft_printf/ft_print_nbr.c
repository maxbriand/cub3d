/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:22:12 by mbriand           #+#    #+#             */
/*   Updated: 2023/12/02 18:12:20 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n == -2147483648)
	{
		ft_print_str("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_print_char('-');
		n *= -1;
		j++;
	}
	if (n > 9)
	{
		i = ft_print_nbr(n / 10);
		ft_print_char(n % 10 + 48);
	}
	if (n < 10 && n >= 0)
		ft_print_char(n + 48);
	i = i + j + 1;
	return (i);
}

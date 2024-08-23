/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:50:17 by mbriand           #+#    #+#             */
/*   Updated: 2023/12/04 19:57:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pt(unsigned long long n, char x, int d)
{
	int	i;

	if (n == 0 && d == 1)
	{
		ft_print_str("(nil)");
		return (5);
	}
	i = 0;
	if (d == 1)
		i += ft_print_str("0x");
	if (n > 15)
	{
		i += ft_print_pt(n / 16, x, 0);
		ft_print_pt(n % 16, x, 0);
	}
	else
		ft_up_or_low(n, x);
	i++;
	return (i);
}

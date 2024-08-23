/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexanbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:50:10 by mbriand           #+#    #+#             */
/*   Updated: 2023/12/02 18:12:14 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexanbr(unsigned int n, char x)
{
	int	i;

	i = 0;
	if (n > 15)
	{
		i = ft_print_hexanbr(n / 16, x);
		ft_print_hexanbr(n % 16, x);
	}
	else
		ft_up_or_low(n, x);
	i++;
	return (i);
}

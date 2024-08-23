/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:50:57 by mbriand           #+#    #+#             */
/*   Updated: 2023/12/02 18:12:40 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i = ft_print_unnbr(n / 10);
		ft_print_unnbr(n % 10);
	}
	else
		ft_print_char(n + '0');
	i++;
	return (i);
}

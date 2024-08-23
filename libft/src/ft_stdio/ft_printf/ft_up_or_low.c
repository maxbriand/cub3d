/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_or_low.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:49:51 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/30 17:45:53 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_up_or_low(int n, char x)
{
	char	low_base[17];
	char	upper_base[17];

	ft_strlcpy(low_base, "0123456789abcdef", 17);
	ft_strlcpy(upper_base, "0123456789ABCDEF", 17);
	if (x == 'x')
		ft_print_char(low_base[n]);
	else if (x == 'X')
		ft_print_char(upper_base[n]);
}

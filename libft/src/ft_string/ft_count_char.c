/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:37:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/28 01:37:20 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(char *s, char ref)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (ref == *s)
			counter++;
		s++;
	}
	return (counter);
}

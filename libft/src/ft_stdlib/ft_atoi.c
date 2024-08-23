/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:13:52 by mbriand           #+#    #+#             */
/*   Updated: 2023/11/27 19:17:56 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	char	test;
	int		i;
	int		total;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	test = nptr[i];
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		test = nptr[i];
		i++;
	}
	total = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total *= 10;
		total += (nptr[i] - 48);
		i++;
	}
	if (test == '-')
		total *= -1;
	return (total);
}

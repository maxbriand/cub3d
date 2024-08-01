/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:41:15 by mbriand           #+#    #+#             */
/*   Updated: 2024/06/03 18:46:30 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return indicator of first occurence of the ref
int	ft_arrfind(char **arr, char *ref)
{
	int	i;

	if (!arr || !ref)
		return (-1);
	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], ref) == 0)
			return (i);
		i++;
	}
	return (-1);
}

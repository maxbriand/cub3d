/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:27:39 by mbriand           #+#    #+#             */
/*   Updated: 2023/11/27 20:54:24 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Create string how map the position of all s char

/*char    f(unsigned int i, char c)
{
	return (c + 1);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapper;
	int		i;

	if (!s)
		return (0);
	mapper = malloc(ft_strlen(s) + 1);
	if (mapper == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		mapper[i] = f(i, s[i]);
		i++;
	}
	mapper[i] = '\0';
	return (mapper);
}

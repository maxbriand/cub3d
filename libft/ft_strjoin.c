/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:36:03 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/07 14:44:16 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		f;
	char	*str;

	f = 0;
	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1)+1);
	i = ft_strlen(s1);
	str[i] = s2[f];
	while ((unsigned long int)i < ft_strlen(s1) + ft_strlen(s2))
	{
		str[i] = s2[f];
		f++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

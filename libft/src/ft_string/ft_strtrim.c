/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:46:00 by mbriand           #+#    #+#             */
/*   Updated: 2023/11/28 22:00:26 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// trimmed = cut at the beginning and at the end
// return 0 if it's not in the set and 1 if it is
// Note: if i == j after first loop, that block the second loop to don't
	// same char

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trimmed;
	int		i;
	int		j;
	int		k;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i])
		i++;
	while (ft_strrchr(set, s1[j - 1]) != 0 && j > 0 && i != j)
		j--;
	s1_trimmed = malloc((j - i) + 1);
	if (s1_trimmed == NULL)
		return (0);
	while (i < j && s1[i])
	{
		s1_trimmed[k] = s1[i];
		i++;
		k++;
	}
	s1_trimmed[k] = '\0';
	return (s1_trimmed);
}

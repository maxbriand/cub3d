/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:22:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/30 17:47:33 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_occurence(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
			counter++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (counter);
}

static char	*new_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return ((char *)(s + i));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		counter;
	int		cur_array;
	char	**pt_ar;

	i = 0;
	cur_array = 0;
	counter = 0;
	pt_ar = malloc(8 * ft_str_occurence(s, c) + 8);
	if (pt_ar == NULL)
		return (NULL);
	while (cur_array < ft_str_occurence(s, c) && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i + counter] != c && s[i + counter])
			counter++;
		pt_ar[cur_array] = malloc(counter + 1);
		ft_strlcpy(pt_ar[cur_array], &s[i], (new_strchr(&s[i], c) - &s[i]) + 1);
		i += counter;
		counter = 0;
		cur_array++;
	}
	pt_ar[cur_array] = NULL;
	return (pt_ar);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:47:27 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/07 18:23:05 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_start(const char *s1, const char *set)
{
	int	i;
	int	start;
	int	remake;

	i = 0;
	start = 0;
	remake = 1;
	while (remake == 1)
	{
		remake = 0;
		i = 0;
		while (set[i] != '\0')
		{
			while (s1[start] == set[i])
			{
				start++;
				remake = 1;
			}
			i++;
		}
	}
	return (start);
}

static int	set_end(const char *s1, const char *set)
{
	int	i;
	int	end;
	int	remake;

	i = 0;
	end = ft_strlen(s1);
	remake = 1;
	while (remake == 1)
	{
		remake = 0;
		i = 0;
		while (set[i] != '\0')
		{
			while (s1[end - 1] == set[i])
			{
				end--;
				remake = 1;
			}
			i++;
		}
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	len;

	if (s1 == 0)
		return (0);
	start = set_start(s1, set);
	end = set_end(s1, set);
	len = end - start;
	s1 = ft_substr(s1, start, len);
	return ((char *)s1);
}

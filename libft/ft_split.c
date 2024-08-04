/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:15:13 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/14 13:15:19 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_c(const char *s, char c)
{
	int	f;
	int	i;

	i = 0;
	f = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] == c)
			while (s[i] == c)
				i++;
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				f++;
		}
		else
			i++;
	}
	f++;
	return (f);
}

static char	**verif(struct s_Variable *point, const char *s, char c, char **str)
{
	size_t	len;

	while (s[point->i] != '\0')
	{
		if (s[point->i] == c)
		{
			len = point->i - point->lastf;
			str[point->f] = ft_substr(s, point->lastf, len);
			point->f = point->f + 1;
			while (s[point->i] == c)
				point->i = point->i + 1;
			point->lastf = point->i;
		}
		else
			point->i = point->i + 1;
	}
	if (s[point->i - 1] != c)
	{
		len = point->i - point->lastf;
		str[point->f] = ft_substr(s, point->lastf, len);
		point->f++;
	}
	str[point->f] = 0;
	return (str);
}

static char	**write_str(struct s_Variable *point, const char *s, char c)
{
	char	**str;

	point->f = strlen_c(s, c);
	str = malloc(sizeof(char *) * (point->f + 1));
	if (!str)
		return (NULL);
	point->i = 0;
	while (s[point->i] == c)
		point->i = point->i + 1;
	point->lastf = point->i;
	point->f = 0;
	str = verif(point, s, c, str);
	return (str);
}

static char	**if_str_empty(void)
{
	char	**str;

	str = malloc(sizeof(char *));
	if (!str)
		return (0);
	str[0] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	struct s_Variable	point;
	char				**str;

	if (s == 0)
		return (0);
	if (ft_strlen(s) == 0)
		return (if_str_empty());
	str = write_str(&point, s, c);
	return (str);
}

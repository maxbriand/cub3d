/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_better.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:22:55 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:22:56 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//use %s somewere inside the char *s like printf to add something in the string
char	*ft_strdup_better(char *s, char *arg)
{
	char	*sdup;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == 's')
		{
			sdup = ft_substr(s, 0, i);
			sdup = ft_strjoin(sdup, arg);
			i += 2;
			sdup = ft_strjoin(sdup, ft_substr(s, i, ft_strlen(s)));
			return (sdup);
		}
		i++;
	}
	return (NULL);
}

//free the arg send as a parameter
char	*ft_better_strdup_free(char *s, char *arg)
{
	char	*sdup;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == 's')
		{
			sdup = ft_substr(s, 0, i);
			sdup = ft_strjoin_free(sdup, arg);
			i += 2;
			sdup = ft_strjoin_free(sdup, ft_substr(s, i, ft_strlen(s)));
			return (sdup);
		}
		i++;
	}
	sdup = ft_strdup(arg);
	free(arg);
	return (sdup);
}

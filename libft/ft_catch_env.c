/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:21:39 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:21:40 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return the line after the env 'str'. Free str.
char	*ft_catch_env(char **envp, char *str)
{
	int		y;
	char	*path;

	y = 0;
	path = NULL;
	while (envp[y] != NULL)
	{
		if (ft_strncmp(envp[y], str, ft_strlen(str)) == 0
			&& envp[y][ft_strlen(str)] == '=')
		{
			path = ft_strdup(&envp[y][ft_strlen(str) + 1]);
			if (!path)
				return (NULL);
			free(str);
			return (path);
		}
		y++;
	}
	free(str);
	return (path);
}

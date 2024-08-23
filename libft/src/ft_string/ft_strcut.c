/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:17:22 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/06 17:56:34 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
Malloc inside:
- return 0 = failed
- no allocation if str is not cut == set a condition when I use free
Get a pointer on new string cut at 'c' pos of str
Return str if c is not found
*/

char	*ft_strcut(char *str, char c)
{
	char	*cutstr;
	size_t	cutstr_len;

	if (ft_strchr(str, c) == 0)
		return (str);
	cutstr_len = ft_strchr(str, c) - str;
	cutstr = ft_substr(str, 0, cutstr_len);
	return (cutstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:31:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/11 21:16:26 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_store_map(t_data *data, char *text)
{
	char *c_line;

	c_line = text;
	while (*text)
	{
		while (ft_isspace(*text) && *text != '\n')
			text++;
		if (*text == '\n')
			c_line = text;
		else if (!*text)
			break ;	
		else
		{
			data->map.map = ft_split(c_line, '\n');
			return ;
		}
		text++;
	}
}

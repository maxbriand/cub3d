/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:41:39 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/25 20:03:11 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_new_full_text(t_data *data, char *full_text, char *buffer)
{
	char	*old_full_text;

	old_full_text = full_text;
	// full_text = ft_strjoin(full_text, buffer);
	full_text = NULL;
	free(old_full_text);
	if (!full_text)
	{
		free(buffer);
		ft_pexit("malloc issue", data);
	}
	return (full_text);
}

char	*ft_get_text(t_data *data, char *path)
{
	int		fd;
	char	*buffer;
	char	*full_text;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_pexit("open function issue", data);
	full_text = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (full_text != NULL)
			full_text = ft_new_full_text(data, full_text, buffer);
		else
			full_text = ft_strdup(buffer);
		free(buffer);
	}
	close(fd);
	return (full_text);
}

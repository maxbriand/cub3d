/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:48:41 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/11 23:47:14 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Extracts string up to newline or end; allocates memory.
static char	*get_head(char *s)
{
	char	*str_output;
	int		len_output;

	if (s == NULL)
		return (NULL);
	if (ft_strchr_two(s, '\n') == 0)
		len_output = ft_strlen_two(s) + 1;
	else
		len_output = ft_strchr_two(s, '\n') - s + 2;
	if (len_output == 0)
		return (0);
	str_output = malloc(len_output);
	if (str_output == NULL)
		return (0);
	ft_strlcpy_two(str_output, s, len_output);
	return (str_output);
}

// Returns string after newline; frees input if specified.
static char	*get_tail(char *s, int i)
{
	char	*str_output;
	int		len_output;

	if (ft_strchr_two(s, '\n') == 0 || s == NULL)
	{
		if (i == 1)
			free (s);
		return (NULL);
	}
	len_output = ft_strlen_two(ft_strchr_two(s, '\n') + 1) + 1;
	str_output = malloc(len_output);
	if (str_output == NULL)
		return (0);
	ft_strlcpy_two(str_output, ft_strchr_two(s, '\n') + 1, len_output + 1);
	if (i == 1)
		free (s);
	if (str_output[0] == 0)
	{
		free(str_output);
		str_output = NULL;
	}
	return (str_output);
}

// Frees memory based on newline presence and buffer_len condition.
static void	free_str(char *line, char *tail, char *buffer, int buffer_len)
{
	if (buffer_len == -1)
	{
		free (buffer);
		return ;
	}
	if (ft_strchr_two(line, '\n') == 0)
	{
		free (tail);
		free (buffer);
	}
}

// Appends buffer to line; handles line initialization.
static char	*fill_line(char *line, char *buffer, int buffer_len)
{
	buffer[buffer_len] = '\0';
	if (line == NULL)
		line = get_head(buffer);
	else
		line = ft_strjoin_two(line, get_head(buffer));
	return (line);
}

// Reads line from files descriptors; manages memory and tail buffer.
char	*get_next_line(int fd)
{
	int			buffer_len;
	char		*buffer;
	char		*line;
	static char	*tail[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer_len = BUFFER_SIZE;
	line = get_head(tail[fd]);
	tail[fd] = get_tail(tail[fd], 1);
	while (tail[fd] == NULL && ft_strchr_two(line, '\n') == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (0);
		buffer_len = read(fd, buffer, BUFFER_SIZE);
		if (buffer_len == 0 || buffer_len == -1)
			break ;
		line = fill_line(line, buffer, buffer_len);
		tail[fd] = get_tail(buffer, 0);
		free (buffer);
	}
	free_str(line, tail[fd], buffer, buffer_len);
	return (line);
}

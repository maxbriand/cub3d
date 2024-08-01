/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:04:09 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/28 01:36:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr_two(const char *s, int c);
char	*ft_strjoin_two(char *s1, char *s2);
size_t	ft_strlcpy_two(char *dst, const char *src, size_t size);
size_t	ft_strlen_two(const char *s);

#endif

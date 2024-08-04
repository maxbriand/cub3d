/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:23:13 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/04 21:40:30 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/time.h>

typedef struct s_data
{
    char    *no_path;
    char    *so_path;
    char    *we_path;
    char    *ea_path;
    int     floor_r;
    int     floor_g;
    int     floor_b;
    int     ceil_r;
    int     ceil_g;
    int     ceil_b;
} t_data;

// ERROR
void	ft_pexit(char *msg);

// PARSING
void	ft_parsing(int ac, char **av);
void	ft_arg_nbr(int ac);
void	ft_extension(char *path);
char	*ft_get_text(char *path);

#endif

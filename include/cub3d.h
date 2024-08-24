/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <mbriand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:23:13 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/24 19:58:37 by mbriand          ###   ########.fr       */
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
# include <stdbool.h>
# include "MLX42/MLX42.h"

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		lenmap;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		ceil_r;
	int		ceil_g;
	int		ceil_b;
	int		len_counter;
}	t_map;

typedef struct s_data
{
	char	*text;
	int		x_spoint;
	int		y_spoint;
	t_map	map;
}   t_data;


// ERROR
void	ft_pexit(char *msg, t_data *data);

// PARSING
void	ft_parsing(t_data *data, int ac, char **av);
void	ft_check_arg_nbr(t_data *data, int ac);
void	ft_check_map_file_extension(t_data *data, char *path);
char	*ft_get_text(t_data *data, char *path);
void 	ft_cut_text(t_data *data);
void 	ft_init_data(t_data *data);
void	ft_store_map(t_data *data, char *text);
void	ft_check_ids_good_path(t_data *data);
void	ft_check_map_one_good_char(t_data *data, char **map);
void	ft_check_map_closed(t_data *data, char **map);

#endif

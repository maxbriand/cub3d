/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:23:13 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 12:02:04 by gmersch          ###   ########.fr       */
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
	char			spawning_orientation;
	char			**map;
	char			**map_copy;
	int				height_map;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	mlx_texture_t	*t_no_path;
	mlx_texture_t	*t_so_path;
	mlx_texture_t	*t_we_path;
	mlx_texture_t	*t_ea_path;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceil_r;
	int				ceil_g;
	int				ceil_b;
	int				len_counter;
}	t_map;

typedef struct s_data
{
	char	*text;
	int		x_spoint;
	int		y_spoint;
	t_map	map;
}	t_data;

// EXE
// void	ft_init_png(t_data *data);

// ERROR
void	ft_pexit(char *msg, t_data *data);

// PARSING
void	ft_parsing(t_data *data, int ac, char **av);
void	ft_check_arg_nbr(t_data *data, int ac);
void	ft_check_map_file_extension(t_data *data, char *path);
char	*ft_get_text(t_data *data, char *path);
void	ft_cut_text(t_data *data);
void	ft_init_data(t_data *data);
void	ft_init_png(t_data *data);
void	ft_store_map(t_data *data, char *text);
void	ft_check_ids_good_path(t_data *data);
void	ft_check_map_one_good_char(t_data *data, char **map);
void	ft_check_map_closed(t_data *data, char **map);
int		ft_atol_color(t_data *data, char *text, int d);
int		ft_set_color(t_data *data, char *text, int nbr);
int		ft_set_orientation(t_data *data, char *text, int nbr);
void	ft_check_map_size(t_data *data, char **map);
float	ft_redefine_pi(float nb);

#endif

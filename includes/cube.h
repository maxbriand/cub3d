/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/13 16:40:21 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42/MLX42.h"
# include <math.h>
# include "../libft/include/libft.h"
# include "parsing.h"

typedef struct s_ray_casting
{
	float	angle;
	float	ray_dirx;
	float	ray_diry;
	int		mapx;
	int		mapy;
	float	side_distx;
	float	side_disty;
	float	delta_distx;
	float	delta_disty;
	int		stepx;
	int		stepy;
	int		side;
	int		hit;
	float	perp_wall_dist;
	float	last_pwd;
	float	distance_factor;
	float	wall_height;
	int		draw_start;
	int		draw_end;
	float	wall_hit_position;
}	t_ray_casting;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				width;
	int				height;
	int				mid_sx;
	int				mid_sy;
	bool			pause;
	mlx_texture_t	*text;
	uint32_t		*color_ray_text;
	mlx_texture_t	*dark_t;
	mlx_texture_t	*flash_t;
	mlx_image_t		*dark;
	mlx_image_t		*flash;
	mlx_image_t		*fps;
	mlx_image_t		*fps_min;
	mlx_image_t		*fps_max;
	char			*fps_mini;
	char			*fps_maxi;
	uint32_t		*color_north;
	uint32_t		*color_south;
	uint32_t		*color_west;
	uint32_t		*color_east;
}	t_game;

typedef struct s_player
{
	float			posx;
	float			posy;
	float			move_speed;
	float			fov;
	float			or;
	bool			player_move_f;
	bool			player_move_b;
	bool			player_move_r;
	bool			player_move_l;
	bool			light_on;
	bool			player_look_left;
	bool			player_look_right;
	bool			player_run;
	float			last_mouse_x;
	float			last_mouse_y;
	t_ray_casting	*rc;
	t_game			*game;
	t_data			*data;
}	t_player;

t_player	*ft_define_player(t_data *data);
void		ft_define_color_text(t_player *p);

void		ft_define_rc(t_player *p, int ex);
void		ft_ultimate_free(t_player *p);

void		ft_ray_casting(void *param);
void		ft_print_ray(t_player *p, int sx);
void		ft_print_fps(t_player *p, suseconds_t usec,
				time_t sec, struct timeval time);

void		ft_move_hook(mlx_key_data_t keydata, t_player *p);
void		ft_move_wasd(t_player *p);

void		ft_mouse_move(t_player *p);
void		ft_key_hook(mlx_key_data_t keydata, void *param);

#endif
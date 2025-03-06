/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/22 21:16:44 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42/MLX42.h"
# include <math.h>
# include "../libft/include/libft.h"
# include "cub3d.h"

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
	bool			cinematic;
	bool			fullscreen;
	bool			print_fps;
}	t_game;

typedef struct s_freddy
{
	float	posy;
	float	posx;
	float	bufx;
	float	bufy;
	bool	right;
	mlx_texture_t	*freddy_left;
	mlx_texture_t	*freddy_right;
	mlx_image_t		*fr;
	mlx_image_t		*fl;
	mlx_texture_t	*flook;
	mlx_image_t		*look;
	mlx_texture_t	*fgolden;
	mlx_image_t		*golden;
	
	bool			visible;
	

}	t_freddy;


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

	float			buf_or;
	float			buf_fov;
	float			buf_py;
	float			buf_px;
	
	
	float			p_height;
	float			p_look_angle;

	//cinematic
	float			last_px;
	float			last_py;
	float			last_value;
	bool			footstep;
	bool			up;
	bool			start_run;
	bool			seen;
	int				last_nb;

	char			*freddy_walk;
	//end cinematic
	
	t_ray_casting	*rc;
	t_game			*game;
	t_data			*data;
	t_freddy		*f;
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

void		ft_define_cinematic(t_player *p);
void		ft_cinematic(t_player *p);

float		ft_abs(float nb);
float		normalize_angle(float angle);
float		normalize_angle_diff(float angle);



void	ft_print_freddy(t_player *p);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 15:24:21 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBE_H
#define CUBE_H

//#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "../libft/include/libft.h"
#include "cub3d.h"

typedef struct s_ray_casting
{

	float angle;//angle of the ray

	float rayDirX; // la direction du rayon
	float rayDirY;


	//index of what tiles of the map we'r talking
	int mapX;
	int mapY;

	//length of the ray from the player to the wall hit
	float sideDistX;
	float sideDistY;

	//idk
	float deltaDistX;
	float deltaDistY;

	//step is the side of the ray fired;
	int stepX;
	int stepY;

	//side of the wall hit, for change color with
	int side;

	//do we have hit a wall ?
	int hit;

	//distance to the player from the mid of the wall, for remove fishy due to distance
	float perpWallDist;

	float	last_pwd;
	float	distance_factor;

	//height of the wall, calculated with the distance from player
	float wall_height;

	//draw pixel in windows mlx
	int drawStart;
	int drawEnd;

	float wall_hit_position;

}t_ray_casting;


typedef struct s_game
{
	mlx_t *mlx;
	mlx_image_t* image;

	//size of the screen
	int width;
	int height;

	//mid screen x
	int mid_sx;
	int mid_sy;

	bool	pause;

	float	brightness; //pour la luminosite

	mlx_texture_t *text;
	uint32_t	*color_ray_text;

	mlx_texture_t* dark_t;
	mlx_texture_t* flash_t;

	mlx_image_t* dark;
	mlx_image_t* flash;
	mlx_image_t* fps;
	mlx_image_t* fps_min;
	mlx_image_t* fps_max;
	char	*fps_mini;
	char	*fps_maxi;


	uint32_t	*color_north;
	uint32_t	*color_south;
	uint32_t	*color_west;
	uint32_t	*color_east;

}t_game;

typedef struct s_player
{
	//char **map;
	//pos of the player in map
	float			posX;
	float			posY;

	float			move_speed;

	//fov and orientation of the player look;
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

}t_player;



t_player	*ft_define_player();
void		ft_define_rc(t_player *p, int ex);
void		ft_ultimate_free(t_player *p);

void		ft_ray_casting(void *param);
void		ft_print_ray(t_player *p, int sx);

void		ft_move_hook(mlx_key_data_t keydata, t_player *p);
void		ft_move_wasd(t_player *p);

void		ft_mouse_move(t_player *p);
void		ft_key_hook(mlx_key_data_t keydata, void *param);

#endif
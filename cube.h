/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/14 15:47:21 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBE_H
#define CUBE_H

//#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

typedef struct s_ray_casting
{

	float angle;//angle of the ray
	
	float rayDirX; // la direction du rayon
	float rayDirY;


	
	float x; //commence a etre egale a la pos du joueur
			//mais est le "trait" du rayon en soit
	float y;

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

	//height of the wall, calculated with the distance from player
	float wall_height;

	//draw pixel in windows mlx
	int drawStart;
	int drawEnd;
	
}t_ray_casting;


typedef struct s_game
{
	mlx_t *mlx;
	mlx_image_t* image;
	
	//size of the screen
	int width;
	int height;
	
}t_game;

typedef struct s_player
{
	//pos of the player in map
	float posX;
	float posY;

	//fov and orientation of the player look;
	float fov;
	float or;

	t_ray_casting *rc;
	t_game *game;

}t_player;



t_player	*ft_define_player();
void		ft_define_rc(t_player *p, int ex);
void		ft_ultimate_free(t_player *p);

void		ft_ray_casting(t_player *p, char map[7][11]);

#endif
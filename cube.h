/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:35:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/12 19:09:47 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBE_H
#define CUBE_H

#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

typedef struct s_rayCasting
{
	float x; //commence a etre egale a la pos du joueur
			//mais est le "trait" du rayon en soit
	float y;

	//index of what tiles of the map we'r talking
	int mapX;
	int mapY;

	//idk
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
	float Wall_height

	//draw pixel in windows mlx
	int drawStart;
	int drawEnd;
	
}t_rayCasting;


#endif
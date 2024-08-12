/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:36:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/12 18:58:51 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int argc, char **argv)
{
	//position du personnage, en partant du fait que 1 carre = 100 sur la map
	float posX = 8.50;
	float posY = 3.50; //x and y start position
	int width = 1920;
	int height = 1080;

	float dirX;
	float dirY;//initial direction vector en face du perso
	float fov = 0.4 * M_PI;
	float or = 1 * M_PI;

	float angle;
	float rayDirX; // la direction du rayon
	float rayDirY;

	char map[7][11] = {"1111111111\0",
					   "1000100011\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0",
					   ""};
	mlx_t *mlx;
	mlx = mlx_init(width, height, "test gala", true);
	//protec

	mlx_image_t* image = mlx_new_image(mlx, width, height);
	if (!image)
	{
		mlx_terminate(mlx);
		return (-1);
	}

	mlx_set_setting(MLX_STRETCH_IMAGE, 1);

	int Ex;
	Ex = 0;
	dirX = cos(or);
	dirY = sin(or);

	while (Ex < width)
	{
		ft_define_rc_arg()
		//connaitre quel cote le mur est
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (mapY < 0 || mapY >= 7 || mapX < 0 || mapX >= (int)ft_strlen(map[mapY]))
				hit = 1;
			if (map[mapY][mapX] == '1')
				hit = 1;
		}
		//fin


		//calcule pour enlever le fishy
		
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
    	else
			perpWallDist = (sideDistY - deltaDistY);
		// float distance = sqrt(pow(x - posX, 2.0) + pow(y - posY, 2.0));
		// float Wall_height = (height / ((distance * cos(or - angle)) / 100.0));
		Wall_height = (height / (perpWallDist * cos(or - angle))); // change
		Wall_height = floor(Wall_height * 10.0) / 10.0;
		//fin


		//dessiner le rayon :
		drawStart = - Wall_height / 2.0 + (float)height / 2.0;
		drawEnd = Wall_height / 2.0 + (float)height / 2.0;
		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= height)
			drawEnd = height - 1.0;
		int k =0;
		int	color = 0xB400B4FF;
		if (side)
			color = (color / 2) | 0xFF;
		while (k < drawStart)
		{
			mlx_put_pixel(image, Ex, k, 0x0000B4FF); // Violet pour le mur
			k++;
		}
		while (k < drawEnd)
		{
			mlx_put_pixel(image, Ex, k, color); // Violet pour le mur
			k++;
		}
		k -= 2;
		while (k < height)
		{
			mlx_put_pixel(image, Ex, k, 0x000000FF); // Violet pour le mur
			k++;
		}
		//end print



		Ex++;
	}




	mlx_image_to_window(mlx, image, 0, 0);
	//mlx_loop_hook(mlx, move_hook(), t_)
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	return (0);
}
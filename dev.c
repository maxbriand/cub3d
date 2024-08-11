#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

#define TILE_SIZE 100

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

	float y;
	float x; //commence a etre egale a la pos du joueur, mais est le "trait" du rayon en soit
	int hit; //prevent infinit loop
	while (Ex < width)
	{
		y = posY;
		x = posX;
		//trouver la longueur du rayon
		angle = or - (fov / 2.0) + (fov * ((float)Ex / width));
		rayDirX = cos(angle);
		rayDirY = sin(angle);
		hit = 0;


		// while (map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)] == '0')
		// {
		// 	x += rayDirX * 0.1;
		// 	y += raydirY * 0.1;
		// 	hit++;
		// 	//protect infinit
		// }



		int mapX = (int)posX;
		int mapY = (int)posY;

		float sideDistX;
		float sideDistY;

		float deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		float deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));



		int stepX;
		int stepY;

		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

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
			if (mapY < 0 || mapY >= 7 || mapX < 0 || mapX >= ft_strlen(map[mapY]))
				hit = 1;
			if (map[mapY][mapX] == '1')
				hit = 1;
		}

		float perpWallDist;
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
    	else
			perpWallDist = (sideDistY - deltaDistY);
		// float distance = sqrt(pow(x - posX, 2.0) + pow(y - posY, 2.0));
		// float Wall_height = (height / ((distance * cos(or - angle)) / 100.0));
		float Wall_height = (height / perpWallDist);

		//dessiner le rayon :
		int drawStart = - Wall_height / 2.0 + height / 2.0;
		int drawEnd = Wall_height / 2.0 + height / 2.0;
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
		while (k < height)
		{
			mlx_put_pixel(image, Ex, k, 0x000000FF); // Violet pour le mur
			k++;
		}
		Ex++;
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop_hook(mlx,)
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	return (0);
}
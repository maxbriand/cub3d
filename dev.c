#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

#define TILE_SIZE 100

int main(int argc, char **argv)
{
	//position du personnage, en partant du fait que 1 carre = 100 sur la map
	float posX = 250;
	float posY = 450; //x and y start position
	int width = 1920;
	int height = 1080;

	float dirX;
	float dirY;//initial direction vector en face du perso
	float fov = 0.6;
	float pi = 3.14159265359;
	float or = 0;

	double rayDirX; // la direction du rayon
	double raydirY;

	char map[6][11] = {"1111111111\0",
					   "1000000001\0",
					   "1011000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					   "1111111111\0"};
	mlx_t *mlx;
	mlx = mlx_init(width, height, "test gala", true);
	//protec

	mlx_image_t* image = mlx_new_image(mlx, width, height);
	if (!image)
	{
		mlx_terminate(mlx);
		return (-1);
	}

	int i; // remplir limage avec le ciel
	i = 0;
	while (i < width)
    {
		int j = 0;
        while (j < height)
        {
            mlx_put_pixel(image, i, j, 0x000000); // Noir pour le ciel
			j++;
        }
		i++;
    }

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
		rayDirX = cos(or - (fov / 2) + (fov * Ex / width));
		raydirY = sin(or - (fov / 2) + (fov * Ex / width));
		hit = 0;
		while (map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)] == '0')
		{
			x += rayDirX * 0.1;
			y += raydirY * 0.1;
			 if (fabs(x - posX) > 1000 || fabs(y - posY) > 1000)
			{
				hit = 1;
				break;
			}
		}
		float distance = sqrt(pow(x - posX, 2) + pow(y - posY, 2));
		int Wall_height = (int)(height / (distance * 0.1)); //ajuste en fonction taille ecran

		//dessiner le rayon :
		 int drawStart = -Wall_height / 2 + height / 2;
		int drawEnd = Wall_height / 2 + height / 2;
		if (drawStart < 0) drawStart = 0;
		if (drawEnd >= height) drawEnd = height - 1;
		
		int k = drawStart;
		while (k < drawEnd)
		{
			mlx_put_pixel(image, Ex, y, 0xB400B4); // Violet pour le mur
			k++;
		}

		Ex++;
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
	return (0);
}
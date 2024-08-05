#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
	//position du personnage, en partant du fait que 1 carre = 100 sur la map
	float posX = 250;
	float posY = 450; //x and y start position
	
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
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne
					   "1121111111\0"};
	mlx_t *mlx;
	mlx = mlx_init(1920, 1080, "test gala", true);

	int Ex;
	Ex = 0;
	dirX = cos(or) + posX;
	dirY = sin(or) + posY; // init du vecteur en face milieu

	float y;
	float x; //commence a etre egale a la pos du joueur, mais est le "trait" du rayon en soit
	y = posY;
	x = posX;
	int i; //prevent infinit loop
	while (Ex < 1920)
	{
		rayDirX = cos(or - (fov / 2)) + posX;
		raydirY = sin(or - (fov / 2)) + posY;
		while (map[(floor(y))][floor(x)] == '0')
		{
			x += rayDirX * 0.1;
			y += raydirY * 0.1;
			i++;
			if (i > 400)
				break ;
		}
		
		Ex++;
	}
}
#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

#define BPP sizeof(int32_t)

typedef struct s_coordinates
{
	uint32_t s_width;
	uint32_t s_height;

	double px;
	double py;
	double dirx;
	double diry;
	double dir_distance = 0.2;

	mlx_image_t* img;
}coord;


void my_keyhook(mlx_key_data_t keydata, void* param)
{


}


int main (int argc, char **argv)
{
	mlx_t *mlx;
	coord *c;

	if (argc != 3)
		return (0);
	c->width = ft_atoi(argv[1]);
	c->height = ft_atoi(argv[2]);

	c->py = 9;
	c->px = 3;
	c->dirx = c->px;
	c->diry = c->py - c->dir_distance;
	mlx = mlx_init(c->width, c->height, "test gala", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	char map[6][11] = {"1111111111\0",
					   "1000000001\0", 
					   "1011000001\0",
					   "1000000001\0",
					   "1000000001\0",// le perso est au deuxieme 0 de cette ligne
					   "1121111111\0"};

	c->img = mlx_new_image(mlx, c->s_width, c->s_height);
	if (!img)
		exit(EXIT_FAILURE);

	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);

	return (0);
}
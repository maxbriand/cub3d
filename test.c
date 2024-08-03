#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>

#define BPP sizeof(int32_t)

int main (int argc, char **argv)
{

	mlx_t *mlx;
	mlx = mlx_init(100 * 10, 100 * 6, "test gala", true);
	if (!mlx)
		exit(EXIT_FAILURE); //pppp

	char map[7][11] = {"1111111111\0",
					   "1000000001\0",
					   "1000000001\0",
					   "1000020001\0",
					   "1000000001\0",
					   "1121111111\0",
					   NULL};


	mlx_image_t* img = mlx_new_image(mlx, 100, 100);
	mlx_image_t* img2 = mlx_new_image(mlx, 100, 100);
	if (!img)
		exit(EXIT_FAILURE); //pppp //proteccc
    memset(img->pixels, 255, img->width * img->height * BPP);
    memset(img2->pixels, 150, img2->width * img2->height * BPP);

	int y = 0;
	int x = 0;
	while (y < 6)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(mlx, img, x * 100, y * 100) < 0)
					exit(EXIT_FAILURE); //pppp
			}
			if (map[y][x] == '2')
			{
				if (mlx_image_to_window(mlx, img2, x * 100, y * 100) < 0)
					exit(EXIT_FAILURE); //pppp
			}
			x++;
		}
		y++;
	}
	// mlx_loop_hook(mlx, ft_hook, mlx);

	//img->instances[0].x += 5; //les instance soint cree apres l'avoir afficher
	//img->instances[0].y += 5;


	mlx_loop(mlx);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_delete_image(mlx, img);
	mlx_delete_image(mlx, img2);
	mlx_terminate(mlx);

	return (0);
}
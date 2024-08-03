#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"

#define BPP sizeof(int32_t)

uint32_t width;
uint32_t height;

//FAUT QUE JE FASSE UNE STRUCT SINON JE PEUX PAS TRANSSMETTRE TOUT;

void change_color(mlx_image_t *img)
{
	uint32_t x;
	uint32_t y;
	int color;
	double px;
	double py;

	px = (3 * (width / 10)) - ((width / 10) / 2);
	x = 0;

	int32_t *pixels = (int32_t *)img->pixels;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			color = 0x0000FF00; //blue
			pixels[y * width + x] = color;
			y++;
		}
		x++;
	}
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	char **argv;
	argv = (char **)param;
	width = ft_atoi(argv[1]);
	height = ft_atoi(argv[2]);
	//change_color();
}


int main (int argc, char **argv)
{

	mlx_t *mlx;
	void *arg;

	arg = &argv;
	if (argc != 3)
		return (0); //printf error




	//init mlx
	mlx = mlx_init(width, height, "test gala", true);
	if (!mlx)
		exit(EXIT_FAILURE); //pppp

	//la map
	char map[6][11] = {"1111111111\0",
					   "1000000001\0", // le perso est au deuxieme 0 de cette ligne
					   "1000000001\0",
					   "1000011001\0",
					   "1000000001\0",
					   "1121111111\0"};

	//l'image qui prend tout l'ecran
	mlx_image_t* img;
	img = mlx_new_image(mlx, width, height);
	if (!img)
		exit(EXIT_FAILURE); //pppp //proteccc
   // memset(img->pixels, 100, img->width * img->height * BPP);

	mlx_key_hook(mlx, my_keyhook, mlx);
	mlx_image_to_window(mlx, img, 0, 0);
	change_color(img);

	// mlx_loop_hook(mlx, ft_hook, mlx);

	//img->instances[0].x += 5; //les instance soint cree apres l'avoir afficher
	//img->instances[0].y += 5;


	mlx_loop(mlx);
	// mlx_set_setting(MLX_MAXIMIZED, true);
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);

	return (0);
}
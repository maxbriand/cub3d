/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:01:19 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/13 15:01:20 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"
#include "MLX42/MLX42.h"
#include <math.h>
#include "libft/libft.h"


int main(void)
{
	float tiles = 100.0;
	float width = 1920;
	float height = 1080;
	float px = 5;
	float py = 3;

	float Ex = 0;

char map[6][11] = {"1111111111\0",
					"1000100011\0",
					"1000001001\0",
					"1000000001\0",
					"1000000001\0",// le perso est au deuxieme 0 de cette ligne et regarde vers le nord
					"1111111111\0"};
	mlx_t *mlx;
	mlx = mlx_init(width, height, "test gala", true);
	//protec

	mlx_image_t* image = mlx_new_image(mlx, width, height);



	float drowstart = (width / 11) * px;
	float drowend = drowstart + 5;
	float dcolstart = (height / 6) * py;
	float dcolend = dcolstart + 5;
	int y;
	while (Ex < width)
	{
		drowstart = 0;
		drowend  = 0;
		y = 0;
		while (y < width)
		{
			mlx_put_pixel(image, Ex, y, 0x00B400FF); // Violet pour le mur
			drowstart = (width / 11) * px;
			drowend = ((width / 11) * px) + (5);
			if (Ex == drowstart && y == (height / 6) * py)
			{
				while (y < drowend)
				{
					mlx_put_pixel(image, Ex, y, 0x00B4B4FF); // Violet pour le mur
					if (y == ((height / 6) * py) + 5)
						break ;
					y++;
				}
			}
			y++;
		}
		Ex++;
	}



	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_terminate(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:23:11 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/13 17:50:34 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_game	*ft_define_game()
{
	t_game *game;

	game = malloc(sizeof(*game));
	game->width = 1920;
	game->height = 1080;
	game->mlx = mlx_init(game->width, game->height, "Cube3D", true);
	game->image = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->image)
	{
		mlx_terminate(game->mlx);
		return (NULL);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	return (game);
}
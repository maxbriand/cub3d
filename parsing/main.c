/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:24:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/26 00:54:51 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// don't know the function to protect free mlx_texture_t
// so we have to add protections on if mlx_load_png failed
int	main(int ac, char **av)
{
	t_data	data;

	ft_parsing(&data, ac, av);
	ft_init_png(&data);
	ft_arrfree(data.map.map);
	return (0);
}

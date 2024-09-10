/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_color_text.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:42:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 17:57:07 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_define_color_we_ea(t_player *p)
{
	unsigned int	i;

	i = 0;
	while (i < p->data->map.t_we_path->height * p->data->map.t_we_path->width)
	{
		p->game->color_west[i] = ((uint8_t)(p->data->map.t_we_path->pixels[i * \
		4]) << 24) | \
		((uint8_t)(p->data->map.t_we_path->pixels[(i * 4) + 1]) << 16) | \
		((uint8_t)(p->data->map.t_we_path->pixels[(i * 4) + 2]) << 8) | \
		(p->data->map.t_we_path->pixels[(i * 4) + 3]);
		i++;
	}
	i = 0;
	while (i < p->data->map.t_ea_path->height * p->data->map.t_ea_path->width)
	{
		p->game->color_east[i] = ((uint8_t)(p->data->map.t_ea_path->pixels[i * \
		4]) << 24) | \
		((uint8_t)(p->data->map.t_ea_path->pixels[(i * 4) + 1]) << 16) | \
		((uint8_t)(p->data->map.t_ea_path->pixels[(i * 4) + 2]) << 8) | \
		(p->data->map.t_ea_path->pixels[(i * \
		4) + 3]);
		i++;
	}
}

void	ft_define_color_text(t_player *p)
{
	unsigned int	i;

	i = 0;
	while (i < p->data->map.t_no_path->height * p->data->map.t_no_path->width)
	{
		p->game->color_north[i] = ((uint8_t)(p->data->map.t_no_path->pixels[i * \
		4]) << 24) | \
		((uint8_t)(p->data->map.t_no_path->pixels[(i * 4) + 1]) << 16) | \
		((uint8_t)(p->data->map.t_no_path->pixels[(i * 4) + 2]) << 8) | \
		(p->data->map.t_no_path->pixels[(i * 4) + 3]);
		i++;
	}
	i = 0;
	while (i < p->data->map.t_so_path->height * p->data->map.t_so_path->width)
	{
		p->game->color_south[i] = ((uint8_t)(p->data->map.t_so_path->pixels[i * \
		4]) << 24) | \
		((uint8_t)(p->data->map.t_so_path->pixels[(i * 4) + 1]) << 16) | \
		((uint8_t)(p->data->map.t_so_path->pixels[(i * 4) + 2]) << 8) | \
		(p->data->map.t_so_path->pixels[(i * 4) + 3]);
		i++;
	}
	ft_define_color_we_ea(p);
}

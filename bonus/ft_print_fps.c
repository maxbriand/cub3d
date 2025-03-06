/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:22:04 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/21 16:57:51 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_print_maxi_fps(t_player *p, char *fps)
{
	if (!p->game->fps_maxi || ft_atoi(p->game->fps_maxi) < ft_atoi(fps))
	{
		if (p->game->fps_max)
			mlx_delete_image(p->game->mlx, p->game->fps_max);
		if (p->game->fps_maxi)
			free(p->game->fps_maxi);
		p->game->fps_maxi = ft_strdup(fps);
		if (!p->game->fps_maxi)
			ft_ultimate_free(p);
		p->game->fps_max = mlx_put_string(p->game->mlx, \
				p->game->fps_maxi, 90, 10);
	}
	p->game->fps = mlx_put_string(p->game->mlx, fps, 10, 10);
	if (!p->game->fps_max || !p->game->fps)
		ft_ultimate_free(p);
	free(fps);
}

void	ft_print_fps(t_player *p, suseconds_t usec,
		time_t sec, struct timeval time)
{
	char	*fps;

	if (p->game->fps)
		mlx_delete_image(p->game->mlx, p->game->fps);
	if (time.tv_sec == sec)
	{
		fps = ft_itoa((int)(1000000 / (time.tv_usec - usec)));
		if (!fps)
			ft_ultimate_free(p);
		if (!p->game->fps_mini || ft_atoi(p->game->fps_mini) > ft_atoi(fps))
		{
			if (p->game->fps_min)
				mlx_delete_image(p->game->mlx, p->game->fps_min);
			if (p->game->fps_mini)
				free(p->game->fps_mini);
			p->game->fps_mini = ft_strdup(fps);
			if (!p->game->fps_mini)
				ft_ultimate_free(p);
			p->game->fps_min = mlx_put_string(p->game->mlx, p->game->fps_mini, \
			50, 10);
			if (!p->game->fps_min)
				ft_ultimate_free(p);
		}
		ft_print_maxi_fps(p, fps);
	}
}

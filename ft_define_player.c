/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:21 by gmersch           #+#    #+#             */
/*   Updated: 2024/08/13 17:49:12 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_player	*ft_define_player()
{
	//PLAYER NEED TO BE SET WITH PARSING, NOT LIKE THIS
	t_player *p;
	
	p = malloc(sizeof(*p));
	p->game = ft_define_game();
		//if (!mlx_game) need to put pointer
		//return (-1);
	p->posX = 8.50;
	p->posY = 3.50; //x and y start position

	p->fov = 0.4 * M_PI;
	p->or = 1 * M_PI;
	p->rc = NULL; 
	return (p);
}
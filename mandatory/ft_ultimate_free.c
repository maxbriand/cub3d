/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:00:20 by gmersch           #+#    #+#             */
/*   Updated: 2024/09/10 12:28:12 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_ultimate_free(t_player *p)
{
	if (p)
	{
		if(p->game)
		{
			free(p->game);
			if (p->rc)
				free(p->rc);
		}
		
		
		ft_arrfree(p->data->map.map);
		free(p);
	}
}

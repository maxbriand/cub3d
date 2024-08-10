/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:02:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/08 00:09:17 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_data *data, int ac, char **av)
{
	ft_arg_nbr(ac);
	ft_extension(*(av+1));
	data->text = ft_get_text(*(av+1));
	ft_init_data(data);
	
	printf("the bool is : %d\n", data->map.ceil_r);
	ft_catch_ids(data);
	// check if all id are set
	printf("%s\n", data->map.no_path);	
}

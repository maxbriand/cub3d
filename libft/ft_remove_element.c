/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:10:03 by gmersch           #+#    #+#             */
/*   Updated: 2024/06/28 16:10:04 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//remove an element from a char **
void	ft_remove_element(char **array, int id_rm)
{
	int	len;
	int	i;

	len = ft_strlen_array(array);
	i = id_rm;
	free(array[id_rm]);
	while (i < (len - 1))
	{
		array[i] = array[i + 1];
		i++;
	}
	array[len - 1] = NULL;
}

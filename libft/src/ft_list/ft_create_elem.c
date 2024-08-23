/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:03:46 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/02 18:03:47 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Create an element of the list
t_list	*ft_create_elem(void *data)
{
	t_list	*pt_new_elem;

	pt_new_elem = malloc(sizeof(t_list));
	if (pt_new_elem == 0)
		return (NULL);
	pt_new_elem->next = NULL;
	pt_new_elem->data = data;
	return (pt_new_elem);
}

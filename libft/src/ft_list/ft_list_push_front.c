/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:01:44 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/11 23:47:29 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Push an element at the beginning of the list
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*bloc1;

	if (begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		bloc1 = ft_create_elem(data);
		bloc1->next = *begin_list;
		*begin_list = bloc1;
	}
}

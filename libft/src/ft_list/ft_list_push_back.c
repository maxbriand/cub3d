/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:02:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/30 17:44:49 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add a node at the end of the linked list
void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_last_node;
	t_list	*deref_begin_list;

	deref_begin_list = *begin_list;
	new_last_node = ft_create_elem(data);
	while (deref_begin_list->next != NULL)
		deref_begin_list = deref_begin_list->next;
	deref_begin_list->next = new_last_node;
}

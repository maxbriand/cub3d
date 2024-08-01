/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:01:57 by mbriand           #+#    #+#             */
/*   Updated: 2024/05/11 23:48:10 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// All elements in the list are reverse
void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next_one;
	t_list	*current_node;
	t_list	*prev;

	current_node = *begin_list;
	prev = NULL;
	while (current_node != NULL)
	{
		next_one = current_node->next;
		current_node->next = prev;
		prev = current_node;
		current_node = next_one;
	}
}

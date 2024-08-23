/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:02:32 by mbriand           #+#    #+#             */
/*   Updated: 2024/04/02 18:02:46 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*// free all node data
void	free_fct(void *pt_value)
{
	*(int *)pt_value = 0;
}*/

// free all node link
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*store;

	while (begin_list != NULL)
	{
		free_fct(begin_list->data);
		store = begin_list;
		begin_list = begin_list->next;
		free(store);
		store->next = NULL;
	}
}

/*// create a linked list of 3 nodes
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	int		value1 = 10;
	int		value2 = 20;
	int		value3 = 30;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->data = &value1;
	node2->data = &value2;
	node3->data = &value3;

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	ft_list_clear(node1, free_fct);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:39:44 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/19 16:39:47 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*b;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		b = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = b;
	}
}

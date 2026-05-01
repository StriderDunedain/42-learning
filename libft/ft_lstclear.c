/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:49:50 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/05/01 14:59:32 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next = node->next;
		del(node->content);
		free(node);
		node = next;
	}
	*lst = NULL;
}

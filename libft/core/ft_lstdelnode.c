/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:51:12 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/28 14:51:18 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_node(t_list *node)
{
	if (node)
	{
		ft_memdel((void **)&(node->content));
		node->content_size = 0;
		ft_memdel((void **)&(node));
	}
}

void		ft_lstdelnode(t_list **head, size_t position)
{
	t_list *node;
	t_list *previous;
	t_list *next;
	size_t i;

	if (head == NULL)
		return ;
	node = *head;
	if (position == 0)
	{
		*head = node->next;
		free_node(node);
		return ;
	}
	i = 0;
	while (node && ++i != position)
		node = node->next;
	if (node == NULL || node->next == NULL)
		return ;
	previous = node;
	next = node->next->next;
	previous->next = next;
	node = node->next;
	free_node(node);
}

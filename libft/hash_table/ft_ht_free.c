/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:07:08 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/08 15:49:04 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht.h"

static void		ft_node_ht_free(t_node_ht *node)
{
	if (node)
	{
		ft_node_ht_free(node->next);
		ft_memdel((void **)&(node->key));
		ft_memdel((void **)&(node->datum));
		ft_memdel((void **)&(node));
	}
}

void			ft_ht_free(t_ht **p_hash_table)
{
	size_t		i;
	t_node_ht	*node;

	i = 0;
	if (p_hash_table == NULL || *p_hash_table == NULL)
		return ;
	if (p_hash_table && *p_hash_table)
	{
		while (i < (*p_hash_table)->size)
		{
			node = (*p_hash_table)->list[i];
			ft_node_ht_free(node);
			i++;
		}
		ft_memdel((void **)&((*p_hash_table)->list));
		ft_memdel((void **)p_hash_table);
	}
}

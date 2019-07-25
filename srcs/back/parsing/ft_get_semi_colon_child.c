/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_semi_colon_child.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:46:08 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/25 14:22:38 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_is_empty(char *str)
{
	char *tmp;

	if (!(tmp = ft_strtrim(str)))
		return (1);
	if (ft_strlen(tmp) == 0)
	{
		ft_memdel((void **)&tmp);
		return (1);
	}
	ft_memdel((void **)&tmp);
	return (0);
}

static char	**has_syntax_error(char **list)
{
	int		k;

	k = 0;
	while (list[k])
	{
		if (ft_is_empty(list[k]) && list[k + 1])
		{
			ft_dprintf(2, \
				"21sh: syntax error near unexpected token ';'\n");
			ft_list_free(&list);
			return (NULL);
		}
		k++;
	}
	return (list);
}

t_node		**ft_get_semi_colon_child(t_node *node, char *cmd, t_env **copy_env)
{
	char	**list;
	int		k;
	t_node	**child;

	if (!(list = ft_str_separate(cmd, ';')))
		return (NULL);
	child = NULL;
	if (!(list = has_syntax_error(list)))
		return (NULL);
	if (list[0])
	{
		if (!(child = (t_node **)ft_memalloc((ft_list_size(list) + 1)\
			* sizeof(t_node *))))
		{
			ft_list_free(&list);
			return (NULL);
		}
		k = -1;
		while (list[++k] && \
			(child[k] = create_node(TYPE_CMD, list[k], copy_env)))
			;
		node->nb_child = k;
	}
	ft_list_free(&list);
	return (child);
}

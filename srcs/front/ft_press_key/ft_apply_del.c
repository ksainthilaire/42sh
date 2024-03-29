/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 03:05:18 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/08 20:51:12 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	my_outc(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

int			ft_apply_del(t_cmd *cmd)
{
	t_list	*head;
	t_list	*node;
	char	*join;

	head = cmd->head;
	node = ft_lstnew((void *)&(cmd->last_key), sizeof(int));
	ft_lstinsert(&head, node);
	cmd->size = cmd->size + 2;
	join = ft_node_join(head, cmd->size);
	ft_interactive_prompt();
	tputs(tgetstr("ce", NULL), 1, my_outc);
	ft_putstr_fd(join, 0);
	ft_memdel((void **)&join);
	cmd->len = cmd->len - 1;
	if (cmd->len < 0)
		cmd->len = 0;
	return (1);
}

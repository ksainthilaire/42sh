/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:13:08 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/25 00:59:07 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int ft_file_exec(t_env ***p_copy_env, char **argv)
{
	char *command;
	t_node **root;
	int success;
	int fds[3];
	int fd;

	fds[0] = 0;
	fds[1] = 1;
	fds[2] = 2;
	success = 0;
	fd = ft_isatty(0) == 0 ? 0 : open(argv[1], O_RDONLY);
	while (get_next_line(fd, &command) != 0)
	{
		root = ft_syntax_tree_create(command, *p_copy_env);
		if (root && *root)
		{
			execute_tree(*root, p_copy_env, fds, &success);
			ft_syntax_tree_free(root);
		}
		ft_memdel((void **)&command);
	}
	ft_memdel((void **)&command);
	if (fd != 0)
		close(fd);
	return (success);
}
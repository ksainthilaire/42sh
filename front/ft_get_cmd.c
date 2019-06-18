/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 01:53:37 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/18 12:59:56 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"


/*
** Read entirely stdin
*/

int ft_get_cmd(int fd, char **command)
{	
    int ret;
	char *command_tmp;
	char *command_tmp1;

    command_tmp = ft_memalloc(9999*sizeof(char));
	if (fd == 0 && ft_isatty(0))
	{
		char buff[10];

		while (ft_strchr(command_tmp, '\n') == NULL)
		{
			ret = read(fd, buff, 1);
			if (buff[0] != '\x1b') 
			{
				if (buff[0] == '\n')
				{
					break;
				}
				if (ret == 1)
				{
					buff[ret] = 0;
					command_tmp = ft_strcat(command_tmp, buff);
				}
			}
			else
			{
				if (read(STDIN_FILENO, buff, 1) != 1)
				{

				}
				if (read(STDIN_FILENO, buff, 1) != 1)
				{

				}
			}
		}
		*command = command_tmp;
	}
	else
	{

		ret = get_next_line(fd, &command_tmp);
		while (ft_str_brackets_is_valid(command_tmp, ft_strlen(command_tmp)) == 0 && ret >= 0)
		{
			ret = get_next_line(fd, &command_tmp1);
			command_tmp = ft_strjoin(command_tmp, "\n");
			command_tmp = ft_strjoin(command_tmp, command_tmp1);
		}
		*command = command_tmp;
	}
    return (ret);
}
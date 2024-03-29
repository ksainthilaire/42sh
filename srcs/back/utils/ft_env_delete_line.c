/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_delete_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:00:37 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/08 22:40:23 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_env_delete_line(char *prefix, t_env **cpy_environ)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (cpy_environ[i])
	{
		if (ft_env_cmp_prefix(prefix, cpy_environ[i]->line) == 0)
		{
			k = i + 1;
			ft_memdel((void **)&(cpy_environ[i]->line));
			ft_memdel((void **)&(cpy_environ[i]));
			while (cpy_environ[k])
			{
				cpy_environ[k - 1] = cpy_environ[k];
				k++;
			}
			cpy_environ[k - 1] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

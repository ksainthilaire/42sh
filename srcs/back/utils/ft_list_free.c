/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:21:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/08 21:27:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_list_free(char ***p_list)
{
	size_t	i;
	char	**list;

	list = *p_list;
	i = 0;
	while (list && list[i])
	{
		ft_memdel((void **)(&(list[i])));
		i++;
	}
	ft_memdel((void **)(p_list));
}

void	ft_list_free_n(char ***p_list, size_t len)
{
	size_t	i;
	char	**list;

	list = *p_list;
	i = 0;
	while (list && i < len)
	{
		if (list[i])
			ft_memdel((void **)(&(list[i])));
		i++;
	}
	ft_memdel((void **)(p_list));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vars_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 23:40:30 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/03 17:09:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_vars     *ft_vars_get(void)
{
	static t_vars 	*p_vars;

	if (p_vars == NULL)
		p_vars = ft_memalloc(sizeof(t_vars));
    return (p_vars);
}

void     *ft_vars_get_value(long key)
{
	t_vars 	*p_vars;

	p_vars = ft_vars_get();
	if (key == KEY_MUST_EXIT)
		return (&(p_vars->must_exit));
	if (key == KEY_SUCCESS_EXIT)
		return (&(p_vars->success_exit));
	if (key == KEY_COPY_ENV)
		return (&(p_vars->copy_env));
	if (key == KEY_PID)
		return (&(p_vars->pid));
	if (key == KEY_CWD)
		return (&(p_vars->cwd));
	return (NULL);
}
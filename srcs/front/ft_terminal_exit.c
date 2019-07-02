/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:23:04 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/02 01:40:04 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

/*
** Terminal exit and configure the former config
*/


void ft_terminal_exit()
{
	t_vars 	*p_vars;

	p_vars = ft_vars_get();
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &(p_vars->old_config));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 23:23:04 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/20 14:32:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "shell.h"

/*
** Terminal exit and configure the former config
*/


void ft_terminal_exit(t_config *old_config)
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, old_config);
	exit(EXIT_SUCCESS);
}
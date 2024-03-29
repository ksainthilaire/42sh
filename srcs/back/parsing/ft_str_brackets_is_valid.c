/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_brackets_is_valid.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:52:04 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/07/25 14:22:40 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static const char	g_brackets[] =
{
	'{',
	'}',
	'[',
	']',
	'(',
	')',
	'"',
	'"',
	39,
	39,
	0
};

int			which_bracket(char c)
{
	int i;

	i = 0;
	while (g_brackets[i])
	{
		if (g_brackets[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_find_closing(char *str, char closing, size_t len)
{
	size_t	i;
	char	opening;
	int		count;

	i = 1;
	opening = str[0];
	count = 0;
	while (i < len)
	{
		if (str[i] == closing)
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		if (str[i] == opening)
			count++;
		i++;
	}
	return (-1);
}

static int	handle_error(char c)
{
	ft_dprintf(2, \
		"21sh: unexpected EOF while looking for matching %c\n", c);
	return (0);
}

int			ft_brackets_is_valid(char *str, size_t len)
{
	size_t	i;
	int		ret;
	int		i_closing;

	i = -1;
	while (++i < len)
	{
		if ((ret = which_bracket(str[i])) != -1)
		{
			if (ret % 2 == 1)
				return (0);
			else if (((i_closing = ft_find_closing(str + i,\
				g_brackets[ret + 1], len - i))) == -1)
				return (handle_error(str[i]));
			else
			{
				str[i] = ' ';
				str[i_closing + i] = ' ';
				if (ft_brackets_is_valid(str + i + 1, i_closing) == 0)
					return (0);
			}
		}
	}
	return (1);
}

int			ft_str_brackets_is_valid(char *str, size_t len)
{
	char	*tmp;
	int		result;

	tmp = (char *)ft_memalloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (-1);
	tmp = ft_strncpy(tmp, str, len);
	result = ft_brackets_is_valid(tmp, len);
	ft_memdel((void **)&tmp);
	return (result);
}

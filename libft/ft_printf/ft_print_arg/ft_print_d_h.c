/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:19:21 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/05 19:20:20 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nblen_dh(short nb)
{
	size_t	nblen;

	nblen = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		nblen++;
	}
	return (nblen);
}

static char		*ft_dhtoa_offset(short nb, size_t size_allocation)
{
	char	*output;
	size_t	nb_len;
	short	n;

	n = nb;
	if (nb == 0)
		return (ft_strdup_alloc("0", size_allocation));
	if (nb == SHRT_MIN)
		return (ft_strdup_alloc("32768", size_allocation));
	nb_len = ft_nblen_dh(n);
	if (!(output = (char *)ft_memalloc((size_allocation\
		+ 1) * sizeof(*output))))
		return (NULL);
	n = n < 0 ? -n : n;
	output[nb_len] = '\0';
	while (n != 0)
	{
		output[--nb_len] = (n % 10) + '0';
		n /= 10;
	}
	return (output);
}

char			*ft_print_d_h(va_list *ap, t_flag *flag)
{
	char	*output;
	short	tmp_val;
	size_t	size_allocation;
	int		tmp;
	int		sign;

	tmp = va_arg(*ap, int);
	sign = (short)tmp;
	tmp_val = (short)tmp;
	size_allocation = ft_nblen_dh(tmp_val);
	size_allocation = ft_len_to_alloc(size_allocation, flag);
	output = ft_dhtoa_offset(tmp_val, size_allocation);
	output = ft_apply_precision_nb(output, flag, sign);
	output = ft_apply_padding_nb(output, flag, sign);
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_long_long_llu.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:21:49 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t				ft_int_to_print(unsigned long long int nb,
		int size, t_info *info)
{
	size_t					len;
	int						add_precision;

	len = 0;
	add_precision = PRECISION - size;
	add_precision > 0 ? add_precision : (add_precision = 0);
	ft_uint_flags_left(size, add_precision, info);
	ft_uint_flags_right(size, info);
	LEFT_Z += add_precision;
	RIGHT_B -= add_precision;
	len += ft_uint_print_left(info);
	ft_putnbr_st(nb);
	len += ft_uint_print_right(info);
	return (len);
}

size_t						ft_print_unsigned_long_long(va_list *arg,
		t_info *info)
{
	unsigned long long int	nb;
	int						size;
	size_t					len;

	len = 0;
	nb = va_arg(*arg, unsigned long long int);
	if (nb == 0 && IS_PRECISION && PRECISION == 0)
	{
		ft_print_blanks(WIDTH);
		return (len = WIDTH);
	}
	size = ft_uint_size(nb);
	len += size;
	len += ft_int_to_print(nb, size, info);
	return (len);
}

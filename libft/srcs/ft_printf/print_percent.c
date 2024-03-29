/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:20:35 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_print_width(t_info *info)
{
	size_t		len;

	len = 0;
	ft_print_blanks(WIDTH - 1);
	ft_putchar('%');
	len += WIDTH;
	return (len);
}

size_t			ft_print_percent(t_info *info)
{
	size_t		len;

	len = 0;
	if (MINUS)
	{
		ft_putchar('%');
		ft_print_blanks(WIDTH - 1);
		len += WIDTH;
	}
	else if (ZERO)
	{
		ft_print_zeros(WIDTH - 1);
		ft_putchar('%');
		len += WIDTH;
	}
	else if (WIDTH)
		len += ft_print_width(info);
	else
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}

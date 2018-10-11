/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blanks_and_zeros.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:22:32 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_blanks(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_print_zeros(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0');
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:20:09 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_binary(size_t nb)
{
	char	*tab;

	tab = "01";
	if (nb < 2)
		ft_putchar(tab[nb]);
	if (nb >= 2)
	{
		ft_print_binary(nb / 2);
		ft_putchar(tab[nb % 2]);
	}
}

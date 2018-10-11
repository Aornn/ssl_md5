/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:50 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wchar_size(wchar_t c)
{
	size_t		len;

	len = 0;
	if (c <= 127)
		len = 1;
	else if (c <= 2047)
		len = 2;
	else if (c <= 65535)
		len = 3;
	else if (c <= 1114111)
		len = 4;
	return (len);
}

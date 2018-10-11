/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:25:18 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*cpy_dst;
	const char		*cpy_src;
	size_t			i;
	size_t			len;

	i = size;
	cpy_dst = dst;
	cpy_src = src;
	while (i-- && *cpy_dst)
		cpy_dst++;
	len = cpy_dst - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen((char *)cpy_src));
	while (*cpy_src)
	{
		if (i != 1)
		{
			*cpy_dst++ = *cpy_src;
			--i;
		}
		cpy_src++;
	}
	*cpy_dst = '\0';
	return (len + (cpy_src - src));
}

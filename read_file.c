/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:13:20 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:15:01 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*read_file(int fd, t_env *e)
{
	int			ret;
	char		*buf;
	char		*output;
	struct stat	sb;

	fstat(fd, &sb);
	if (fd != 0)//(IS_REG(sbt.mode))
	{
		e->size = sb.st_size;
		buf = ft_memalloc((int)e->size);
		output = ft_memalloc((int)e->size);
		e->size_check = 0;
	}
	else
	{
		e->size = 1;
		buf = ft_strnew(1);
		output = ft_strnew(0);
	}
	while ((ret = read(fd, buf, e->size)))
	{
		if (e->size_check == 1)
		{
			output = ft_strjoin(output, buf);
			free(output);
		}
		else
			ft_memcpy(output, buf, e->size);
	}
	free(buf);
	return (output);
}

uint32_t	reverse_bits(uint32_t value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |\
		(value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

uint32_t	rotate_left(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

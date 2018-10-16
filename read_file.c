/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:13:20 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/16 16:04:44 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	put_size(int fd, t_env *e)
{
	struct stat	sb;

	fstat(fd, &sb);
	if (fd != 0)
	{
		e->size = sb.st_size;
		e->size_check = 0;
	}
	else
		e->size = 2;
	e->tmp_size = e->size;
	if (e->size > 2147483646)
		e->tmp_size = 2147483645;
	return (e->tmp_size);
}

void		check_ret(ssize_t ret)
{
	if (ret == -1)
	{
		ft_putendl("Error while reading");
		exit(1);
	}
}

char		*ft_memjoin(void *s1, void *s2, size_t size, size_t i)
{
	char *res;

	if ((res = malloc((size * i) * sizeof(char))) == NULL)
	{
		ft_putendl("Malloc error");
		exit(1);
	}
	if (s1 != NULL)
	{
		ft_memcpy(res, s1, size);
		ft_memcpy(res + (size * (i - 1)), s2, size);
	}
	else
		ft_memcpy(res, s2, size);
	free(s1);
	return (res);
}

char		*read_file(int fd, t_env *e)
{
	ssize_t		ret;
	char		*buf;
	char		*output;
	struct stat	sb;

	fstat(fd, &sb);
	output = NULL;
	buf = ft_memalloc(put_size(fd, e));
	if (fd == 0)
		output = ft_strnew(0);
	check_value_r(buf, output, fd);
	while ((ret = read(fd, buf, e->tmp_size)) > 0)
	{
		if (e->size_check == 1)
		{
			buf[ret] = '\0';
			output = ft_strjoin_and_free(output, buf, '\0', 1);
		}
		else
			output = ft_memjoin(output, buf, e->tmp_size, e->i);
		e->i++;
	}
	check_ret(ret);
	free(buf);
	return (output);
}

uint32_t	rotate_left(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

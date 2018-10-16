/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:19:46 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/16 16:51:46 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			index_fnc(char *algo)
{
	if (ft_strcmp(algo, "md5") == 0)
		return (md5);
	else if (ft_strcmp(algo, "sha256") == 0)
		return (sha256);
	else if (ft_strcmp(algo, "sha224") == 0)
		return (sha224);
	ft_putstr("Error: ");
	ft_putstr(algo);
	ft_putendl(" is an invalid command");
	return (-1);
}

void		save_arg(t_env *e, int argc, char **argv)
{
	int k;

	k = 1;
	while (k++ < argc - 1)
	{
		if (ft_strcmp(argv[k], "-p") == 0)
			e->option |= OPT_P;
		else if (ft_strcmp(argv[k], "-r") == 0)
			;
		else if (ft_strcmp(argv[k], "-q") == 0)
			;
		else
		{
			if (ft_strstr(argv[k], "-s") != NULL)
			{
				e->option = e->option | OPT_S;
				k++;
			}
			else
			{
				e->option = e->option | OPT_F;
				e->check_files_p = k;
			}
		}
	}
}

void		check_value_r(char *buf, char *output, int fd)
{
	if (fd == 0)
	{
		if (output == NULL)
		{
			ft_printf("Malloc error\n");
			exit(1);
		}
	}
	if (buf == NULL)
	{
		ft_printf("Malloc error\n");
		exit(1);
	}
}

uint32_t	reverse_bits(uint32_t value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |\
	(value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

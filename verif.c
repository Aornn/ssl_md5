/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:19:46 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:19:47 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		index_fnc(char *algo)
{
	if (ft_strcmp(algo, "md5") == 0)
		return (md5);
	else if (ft_strcmp(algo, "sha256") == 0)
		return (sha256);
	ft_putstr("Error: ");
	ft_putstr(algo);
	ft_putendl(" is an invalid command");
	return (-1);
}

void	save_arg(t_env *e, int argc, char **argv)
{
	int i_j[2];

	i_j[0] = 2;
	i_j[1] = 0;
	while (i_j[0] < argc)
	{
		if (ft_strcmp(argv[i_j[0]], "-p") == 0)
		{
			e->option |= OPT_P;
			e->pos_p[i_j[1]] = i_j[0];
			i_j[1]++;
		}
		else if (ft_strcmp(argv[i_j[0]], "-r") == 0)
			e->option = e->option | OPT_R;
		else if (ft_strcmp(argv[i_j[0]], "-q") == 0)
			e->option = e->option | OPT_Q;
		else
		{
			if (ft_strstr(argv[i_j[0]], "-s") != NULL)
				e->option = e->option | OPT_S;
			else
				e->option = e->option | OPT_F;
		}
		i_j[0]++;
	}
}

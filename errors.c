/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:09:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:09:17 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**Handle errors
*/

void	wrong_opt(char **argv, int i)
{
	ft_putstr("md5: illegal option - ");
	ft_putstr(argv[i]);
	exit(1);
}

void	is_directory(char **argv, int i, t_env *e)
{
	ft_printf("%s: %s: Is a directory\n", argv[1], argv[i]);
	e->fail_file = 1;
}

void	no_file(char **argv, int i, t_env *e)
{
	ft_printf("%s: %s: No such file or directory\n", argv[1], argv[i]);
	e->fail_file = 1;
}

void	manage_q(t_env *e, t_select_hash *hash_choose)
{
	if (!(e->option & OPT_F) && !(e->option & OPT_S) &&
			!(e->option & OPT_R))
	{
		create_hash_by_fd(e, 0, hash_choose, 1);
		ft_putstr("\n");
	}
}

void	manage_r(t_env *e, t_select_hash *hash_choose)
{
	if (!(e->option & OPT_F) && !(e->option & OPT_S))
	{
		create_hash_by_fd(e, 0, hash_choose, 1);
		ft_putstr("\n");
	}
}

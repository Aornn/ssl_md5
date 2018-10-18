/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:09:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/17 17:03:24 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	wrong_opt(char **argv, int i)
{
	ft_putstr("md5: illegal option ");
	ft_putendl(argv[i]);
	ft_putendl("usage: [md5 sha256 sha224] [-pqr] [-s string] [files ...]");
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

void	manage_q(t_env *e)
{
	e->option = e->option | OPT_Q;
	if (!(e->option & OPT_F) && !(e->option & OPT_S) &&
			!(e->option & OPT_R) && e->check_q == 0)
	{
		if (e->len_pos_p > 0)
		{
			if (e->index == md5)
				ft_putstr("d41d8cd98f00b204e9800998ecf8427e\n");
			else if (e->index == sha224)
				ft_putstr("d14a028c2a3a2bc9476102bb28823\
				4c415a2b01f828ea62ac5b3e42f\n");
			else if (e->index == sha256)
				ft_putstr("e3b0c44298fc1c149afbf4c8996fb9\
				2427ae41e4649b934ca495991b7852b855\n");
			e->check_q = 1;
		}
		else
		{
			create_hash_by_fd(e, 0, 1);
			ft_putstr("\n");
			e->check_q = 1;
		}
	}
}

void	manage_r(t_env *e)
{
	e->option = e->option | OPT_R;
	if (!(e->option & OPT_F) && !(e->option & OPT_S) && !(e->option & OPT_Q)
			&& e->check_r == 0)
	{
		if (e->len_pos_p > 0)
		{
			if (e->index == md5)
				ft_putstr("d41d8cd98f00b204e9800998ecf8427e\n");
			else if (e->index == sha224)
				ft_putstr("d14a028c2a3a2bc9476102bb28823\
				4c415a2b01f828ea62ac5b3e42f\n");
			else if (e->index == sha256)
				ft_putstr("e3b0c44298fc1c149afbf4c8996fb9\
				2427ae41e4649b934ca495991b7852b855\n");
			e->check_r = 1;
		}
		else
		{
			create_hash_by_fd(e, 0, 1);
			ft_putstr("\n");
			e->check_r = 1;
		}
	}
}

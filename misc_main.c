/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:43:08 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/17 17:03:34 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	manage_p(t_env *e)
{
	if (e->check_p == 0)
	{
		create_hash_by_fd(e, 0, 0);
	}
	else
	{
		if (e->index == md5)
			ft_putstr("d41d8cd98f00b204e9800998ecf8427e");
		else if (e->index == sha224)
			ft_putstr("d14a028c2a3a2bc9476102bb288234c415a2b01f828ea"\
			"62ac5b3e42f");
		else if (e->index == sha256)
			ft_putstr("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca49599"\
			"1b7852b855");
	}
	ft_putstr("\n");
	e->check_p = 1;
}

void	init_var_main(t_env *e, int argc, char **argv)
{
	int i;
	int check_s;

	check_s = 0;
	e->i = 1;
	e->check_f_p = 0;
	e->content = NULL;
	e->check_q = 0;
	e->check_r = 0;
	i = 2;
	while (i < argc)
	{
		if (ft_strstr(argv[i], "-s") != NULL)
			check_s = 1;
		else if (ft_strcmp(argv[i], "-p") == 0 && check_s == 0 &&
		((i < e->check_files_p && e->check_files_p != 0) ||
		(e->check_files_p == 0)))
		{
			e->check_f_p = i;
			manage_p(e);
			e->len_pos_p++;
		}
		i++;
	}
}

void	create_hash_by_fd(t_env *e, int fd, int i)
{
	uint32_t *padding;
	e->content = read_file(fd, e);
	if (i == 0)
		ft_putstr(e->content);
	prepare_data(e);
	padding = ft_padding(e);
	g_hash[e->index].ptr_hash(padding, *e);
	free(e->content);
	free(padding);
}

void	create_hash_by_s(t_env *e, char *in, char *argv)
{
	uint32_t *padding;
	padding = NULL;
	if (!(e->option & OPT_R) && !(e->option & OPT_Q))
		ft_printf("%s (\"%s\") = ", argv, in);
	e->content = ft_strdup(in);
	prepare_data(e);
	padding = ft_padding(e);
	g_hash[e->index].ptr_hash(padding, *e);
	if (e->option & OPT_R && !(e->option & OPT_Q))
		ft_printf(" \"%s\"", in);
	ft_putstr("\n");
	free(e->content);
	free(padding);
}

void	ft_argc_2(t_env *e, int argc)
{
	if (argc == 2)
	{
		create_hash_by_fd(e, 0, 1);
		ft_putstr("\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:43:08 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:10:08 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_var_main(t_env *e, int argc, char **argv)
{
	int i;

	e->len_pos_p = 0;
	e->fail_file = 0;
	e->content = NULL;
	e->pos_p = NULL;
	i = 2;
	e->size_check = 1;
	e->file_check = 0;
	e->option = 00000000;
	if (argv[1] && (e->index = index_fnc(argv[1])) == -1)
		exit(1);
	if (argc < 2)
	{
		ft_putendl("usage: md5 [-pqr] [-s string] [files ...]");
		exit(1);
	}
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-p") == 0)
			e->len_pos_p++;
		i++;
	}
	e->pos_p = malloc(e->len_pos_p * sizeof(int));
}

void	create_hash_by_fd(t_env *e, int fd, t_select_hash *hash_choose, int i)
{
	uint32_t *padding;

	e->content = read_file(fd, e);
	if (i == 0)
		ft_putstr(e->content);
	prepare_data(e);
	padding = ft_padding(e);
	(*hash_choose[e->index])(padding, *e);
	free(e->content);
	free(padding);
}

void	create_hash_by_s(t_env *e, char *in, char *argv,
		t_select_hash *hash_choose)
{
	uint32_t *padding;

	padding = NULL;
	if (!(e->option & OPT_R) && !(e->option & OPT_Q))
		ft_printf("%s (\"%s\") = ", argv, in);
	e->content = ft_strdup(in);
	prepare_data(e);
	padding = ft_padding(e);
	(*hash_choose[e->index])(padding, *e);
	if (e->option & OPT_R && !(e->option & OPT_Q))
		ft_printf(" \"%s\"\n", in);
	if (e->option & OPT_Q)
		ft_putstr("\n");
	free(e->content);
	free(padding);
}

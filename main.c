/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:20:05 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/17 17:04:51 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <inttypes.h>

void	print_s(char **argv, t_env *e, int *i)
{
	if (ft_strlen(argv[*i]) > 2)
		create_hash_by_s(e, &argv[*i][2], argv[1]);
	else if (argv[*i + 1])
	{
		create_hash_by_s(e, argv[*i + 1], argv[1]);
		*i = *i + 1;
	}
	else
		ft_putstr("option requires an argument -- s\n");
}

void	manage_s_second(t_env *e, char **argv, int i)
{
	if ((e->fd = open(argv[i], O_DIRECTORY)) != -1)
		is_directory(argv, i, e);
	else if ((e->fd = open(argv[i], O_RDONLY)) < 0)
		no_file(argv, i, e);
	else
	{
		if (!(e->option & OPT_R) && !(e->option & OPT_Q))
			ft_printf("%s (%s) = ", argv[1], argv[i]);
		create_hash_by_fd(e, e->fd, 1);
		if ((e->option & OPT_R) && !(e->option & OPT_Q))
		{
			ft_printf(" %s\n", argv[i]);
			e->option = e->option & OPT_R;
		}
		else
			ft_putstr("\n");
	}
	e->file_check = 1;
}

void	main_loop(int argc, char **argv, t_env *e)
{
	int i;

	i = 1;
	while (i++ < argc - 1)
	{
		if (argv[i][0] == '-' && (argv[i][1] != 'p' && argv[i][1] != 'q' &&
					argv[i][1] != 'r' && argv[i][1] != 's'))
			wrong_opt(argv, i);
		if (ft_strcmp(argv[i], "-r") == 0 && e->file_check == 0)
			manage_r(e);
		else if (ft_strcmp(argv[i], "-q") == 0 && e->file_check == 0)
			manage_q(e);
		else if (ft_strcmp(argv[i], "-p") == 0 && e->file_check == 0)
		{
			if (i > e->check_f_p)
				manage_p(e);
		}
		else
		{
			if (ft_strstr(argv[i], "-s") != NULL && e->file_check == 0)
				print_s(argv, e, &i);
			else
				manage_s_second(e, argv, i);
		}
	}
}

void	error_main(t_env *e, char **argv, int argc)
{
	if (argv[1] && (e->index = index_fnc(argv[1])) == -1)
		exit(1);
	if (argc < 2)
	{
		ft_putendl("usage: [md5 sha256 sha224] [-pqr] [-s string] [files ...]");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_env			e;

	e.check_p = 0;
	e.check_f_p = 0;
	e.len_pos_p = 0;
	e.fail_file = 0;
	e.size_check = 1;
	e.file_check = 0;
	e.option = 00000000;
	error_main(&e, argv, argc);
	save_arg(&e, argc, argv);
	init_var_main(&e, argc, argv);
	ft_argc_2(&e, argc);
	main_loop(argc, argv, &e);
	close(e.fd);
	if (e.fail_file)
		exit(1);
	else
		exit(0);
}

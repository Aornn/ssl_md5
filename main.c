/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:20:05 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:21:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <inttypes.h>

void	ft_argc_2(t_env *e, int argc, t_select_hash *hash_choose)
{
	if (argc == 2)
	{
		create_hash_by_fd(e, 0, hash_choose, 1);
		ft_putstr("\n");
	}
}

void	print_s(char **argv, t_env *e, int *i, t_select_hash *hash_choose)
{
	if (ft_strlen(argv[*i]) > 2)
		create_hash_by_s(e, &argv[*i][2], argv[1], hash_choose);
	else if (argv[*i + 1])
	{
		create_hash_by_s(e, argv[*i + 1], argv[1], hash_choose);
		*i = *i + 1;
	}
	else
		ft_putstr("option requires an argument -- s\n");
}

void	manage_s_second(t_env *e, char **argv, int i,
		t_select_hash *hash_choose)
{
	if ((e->fd = open(argv[i], O_DIRECTORY)) != -1)
		is_directory(argv, i, e);
	else if ((e->fd = open(argv[i], O_RDONLY)) < 0)
		no_file(argv, i, e);
	else
	{
		if (!(e->option & OPT_R) && !(e->option & OPT_Q))
			ft_printf("%s (%s) = ", argv[1], argv[i]);
		create_hash_by_fd(e, e->fd, hash_choose, 1);
		if ((e->option & OPT_R) && !(e->option & OPT_Q))
			ft_printf(" %s\n", argv[i]);
		else
			ft_putstr("\n");
	}
	e->file_check = 1;
}

void	main_loop(int argc, char **argv, t_env *e, t_select_hash *hash_choose)
{
	int i;

	i = 2;
	while (i < argc)
	{
		if (argv[i][0] == '-' && (argv[i][1] != 'p' && argv[i][1] != 'q' &&
					argv[i][1] != 'r' && argv[i][1] != 's'))
			wrong_opt(argv, i);
		if (ft_strcmp(argv[i], "-r") == 0 && e->file_check == 0)
			manage_r(e, hash_choose);
		else if (ft_strcmp(argv[i], "-q") == 0 && e->file_check == 0)
			manage_q(e, hash_choose);
		else if (ft_strcmp(argv[i], "-p") == 0 && e->file_check == 0)
			;
		else
		{
			if (ft_strstr(argv[i], "-s") != NULL && e->file_check == 0)
				print_s(argv, e, &i, hash_choose);
			else
				manage_s_second(e, argv, i, hash_choose);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int				i;
	t_env			e;
	t_select_hash	*hash_choose;

	init_var_main(&e, argc, argv);
	hash_choose = malloc(sizeof(t_select_hash) * nbr_cmd);
	hash_choose[md5] = ft_md5;
	hash_choose[sha256] = ft_sha256;
	ft_argc_2(&e, argc, hash_choose);
	save_arg(&e, argc, argv);
	i = 0;
	while (i < e.len_pos_p)
	{
		create_hash_by_fd(&e, 0, hash_choose, i);
		ft_putstr("\n");
		i++;
	}
	main_loop(argc, argv, &e, hash_choose);
	free(e.pos_p);
	free(hash_choose);
	close(e.fd);
	if (e.fail_file)
		exit(1);
	else
		exit(0);
}

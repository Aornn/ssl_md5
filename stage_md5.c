/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:19:07 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:19:27 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	stage1(t_env_md5 *e_md5)
{
	e_md5->f_g[0] = (e_md5->a_b_c_d[1] & e_md5->a_b_c_d[2]) |
		((~e_md5->a_b_c_d[1]) & e_md5->a_b_c_d[3]);
	e_md5->f_g[1] = e_md5->i;
}

void	stage2(t_env_md5 *e_md5)
{
	e_md5->f_g[0] = (e_md5->a_b_c_d[3] & e_md5->a_b_c_d[1]) |
		((~e_md5->a_b_c_d[3]) & e_md5->a_b_c_d[2]);
	e_md5->f_g[1] = (5 * e_md5->i + 1) % 16;
}

void	stage3(t_env_md5 *e_md5)
{
	e_md5->f_g[0] = e_md5->a_b_c_d[1] ^ e_md5->a_b_c_d[2] ^ e_md5->a_b_c_d[3];
	e_md5->f_g[1] = (3 * e_md5->i + 5) % 16;
}

void	stage4(t_env_md5 *e_md5)
{
	e_md5->f_g[0] = e_md5->a_b_c_d[2] ^ (e_md5->a_b_c_d[1] |
			~e_md5->a_b_c_d[3]);
	e_md5->f_g[1] = (7 * e_md5->i) % 16;
}

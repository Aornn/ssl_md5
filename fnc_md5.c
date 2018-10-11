/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:22:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:12:53 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		init_md5_var(t_env_md5 *e_md5)
{
	e_md5->h0 = 0x67452301;
	e_md5->h1 = 0xefcdab89;
	e_md5->h2 = 0x98badcfe;
	e_md5->h3 = 0x10325476;
	e_md5->i = 0;
	e_md5->l = 0;
	e_md5->temp = 0;
}

void		update_begin_abcd(t_env_md5 *e_md5)
{
	e_md5->a_b_c_d[0] = e_md5->h0;
	e_md5->a_b_c_d[1] = e_md5->h1;
	e_md5->a_b_c_d[2] = e_md5->h2;
	e_md5->a_b_c_d[3] = e_md5->h3;
	e_md5->i = 0;
}

void		update_end_abcd(t_env_md5 *e_md5, uint32_t *padding)
{
	e_md5->f_g[0] += e_md5->a_b_c_d[0] + g_k[e_md5->i] + padding[e_md5->f_g[1]
		+ e_md5->l * 16];
	e_md5->a_b_c_d[0] = e_md5->a_b_c_d[3];
	e_md5->a_b_c_d[3] = e_md5->a_b_c_d[2];
	e_md5->a_b_c_d[2] = e_md5->a_b_c_d[1];
	e_md5->a_b_c_d[1] += rotate_left(e_md5->f_g[0], g_r[e_md5->i]);
}

void		update_h_value(t_env_md5 *e_md5)
{
	e_md5->h0 += e_md5->a_b_c_d[0];
	e_md5->h1 += e_md5->a_b_c_d[1];
	e_md5->h2 += e_md5->a_b_c_d[2];
	e_md5->h3 += e_md5->a_b_c_d[3];
}

void		ft_md5(uint32_t *padding, t_env e)
{
	t_env_md5 e_md5;

	init_md5_var(&e_md5);
	while (e_md5.l < e.multiple_de_512)
	{
		update_begin_abcd(&e_md5);
		while (e_md5.i < 64)
		{
			if (e_md5.i <= 15)
				stage1(&e_md5);
			else if (e_md5.i >= 16 && e_md5.i <= 31)
				stage2(&e_md5);
			else if (e_md5.i >= 32 && e_md5.i <= 47)
				stage3(&e_md5);
			else if (e_md5.i >= 48 && e_md5.i <= 63)
				stage4(&e_md5);
			update_end_abcd(&e_md5, padding);
			e_md5.i++;
		}
		update_h_value(&e_md5);
		e_md5.l++;
	}
	ft_printf("%.8x%.8x%.8x%.8x", reverse_bits(e_md5.h0),
			reverse_bits(e_md5.h1),
			reverse_bits(e_md5.h2), reverse_bits(e_md5.h3));
}

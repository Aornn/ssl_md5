/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_sha256.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:14:49 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:08:49 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		update_middle(t_env_sha256 *e)
{
	e->a = e->h1;
	e->b = e->h2;
	e->c = e->h3;
	e->d = e->h4;
	e->e = e->h5;
	e->f = e->h6;
	e->g = e->h7;
	e->h = e->h8;
}

void		update_end(t_env_sha256 *e)
{
	e->h1 += e->a;
	e->h2 += e->b;
	e->h3 += e->c;
	e->h4 += e->d;
	e->h5 += e->e;
	e->h6 += e->f;
	e->h7 += e->g;
	e->h8 += e->h;
}

void		update_snd_w(t_env_sha256 *e, int j)
{
	e->s_1 = right_rotate(e->e, 6) ^\
		right_rotate(e->e, 11) ^ right_rotate(e->e, 25);
	e->ch = (e->e & e->f) ^ ((~e->e) & e->g);
	e->temp1 = e->h + e->s_1 + e->ch + g_sha256_k[j] + e->w[j];
	e->s_0 = right_rotate(e->a, 2) ^\
		right_rotate(e->a, 13) ^ right_rotate(e->a, 22);
	e->maj = (e->a & e->b) ^ (e->a & e->c) ^ (e->b & e->c);
	e->temp2 = e->s_0 + e->maj;
	e->h = e->g;
	e->g = e->f;
	e->f = e->e;
	e->e = e->d + e->temp1;
	e->d = e->c;
	e->c = e->b;
	e->b = e->a;
	e->a = e->temp1 + e->temp2;
}

void		update_fst_w(t_env_sha256 *e, int i, int j, uint32_t *padding)
{
	if (j < 16)
	{
		e->w[j] = uint32_btl(padding[j + (i * 16)]);
	}
	if (j + (i * 16) == e->nb_blocks - 1 || j + (i * 16) == e->nb_blocks - 2)
	{
		e->w[j] = padding[j + (i * 16)];
	}
	if (j > 15)
	{
		e->s0 = right_rotate(e->w[j - 15], 7) ^\
				right_rotate(e->w[j - 15], 18) ^ (e->w[j - 15] >> 3);
		e->s1 = right_rotate(e->w[j - 2], 17) ^\
				right_rotate(e->w[j - 2], 19) ^ (e->w[j - 2] >> 10);
		e->w[j] = e->w[j - 16] + e->s0 + e->w[j - 7] + e->s1;
	}
}

void		ft_sha256(uint32_t *padding, t_env e_struc)
{
	t_env_sha256	e;
	int				i;
	int				j;

	init_var_sha256(&e, e_struc, &i, &j);
	while (i < e_struc.multiple_de_512)
	{
		while (j < 64)
		{
			update_fst_w(&e, i, j, padding);
			j++;
		}
		update_middle(&e);
		j = 0;
		while (j < 64)
		{
			update_snd_w(&e, j);
			j++;
		}
		update_end(&e);
		j = 0;
		i++;
	}
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x",\
			e.h1, e.h2, e.h3, e.h4, e.h5, e.h6, e.h7, e.h8);
}

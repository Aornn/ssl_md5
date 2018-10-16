/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:14:49 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/16 16:40:26 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	right_rotate(uint32_t n, uint32_t d)
{
	return (n >> d) | (n << (32 - d));
}

uint32_t	uint32_btl(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | ((val >> 16) & 0xFFFF);
}

void		init_var_sha256(t_env_sha256 *e, t_env e_struc,\
uint64_t *i, uint64_t *j)
{
	e->nb_blocks = ((512 * e_struc.multiple_de_512) / 32);
	e->h1 = 0x6a09e667;
	e->h2 = 0xbb67ae85;
	e->h3 = 0x3c6ef372;
	e->h4 = 0xa54ff53a;
	e->h5 = 0x510e527f;
	e->h6 = 0x9b05688c;
	e->h7 = 0x1f83d9ab;
	e->h8 = 0x5be0cd19;
	if (e_struc.index == sha224)
	{
		e->h1 = 0xc1059ed8;
		e->h2 = 0x367cd507;
		e->h3 = 0x3070dd17;
		e->h4 = 0xf70e5939;
		e->h5 = 0xffc00b31;
		e->h6 = 0x68581511;
		e->h7 = 0x64f98fa7;
		e->h8 = 0xbefa4fa4;
	}
	*i = 0;
	*j = 0;
}

void		disp_sha256(t_env_sha256 e, t_env e_struc)
{
	if (e_struc.index == sha256)
	{
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x",\
				e.h1, e.h2, e.h3, e.h4, e.h5, e.h6, e.h7, e.h8);
	}
	else
	{
		ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x",\
				e.h1, e.h2, e.h3, e.h4, e.h5, e.h6, e.h7);
	}
}

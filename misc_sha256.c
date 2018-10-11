/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:14:49 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:10:47 by rqueverd         ###   ########.fr       */
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

void		init_var_sha256(t_env_sha256 *e, t_env e_struc, int *i, int *j)
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
	*i = 0;
	*j = 0;
}

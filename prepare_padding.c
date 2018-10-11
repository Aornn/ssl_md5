/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:15:09 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/11 11:18:51 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		prepare_data(t_env *e)
{
	if (e->size_check == 1)
		e->size = ft_strlen(e->content);
	e->input_bitsize = e->size * 8;
	e->multiple_de_512 = ((e->size * 8 + 64) / 512) + 1;
	if (e->size % 4 == 0)
		e->nbr_tab_content = (int)e->size / 4;
	else
		e->nbr_tab_content = (int)e->size / 4 + 1;
	e->nb_zero = (512 * e->multiple_de_512) - (64 + 1 + e->size * 8);
}

uint32_t	*put_zero(uint32_t *padding, int nb_blocks)
{
	int i;

	i = 0;
	while (i < nb_blocks)
	{
		padding[i] = 0;
		i++;
	}
	return (padding);
}

uint32_t	*add_size(uint32_t *padding, int nb_blocks, t_env *e)
{
	if (e->index == md5)
	{
		padding[nb_blocks - 1] = ((e->size * 8) >> 32) & 0xffffffff;
		padding[nb_blocks - 2] = (e->size * 8) & 0xffffffff;
	}
	else
	{
		padding[nb_blocks - 2] = ((e->size * 8) >> 32) & 0xffffffff;
		padding[nb_blocks - 1] = (e->size * 8) & 0xffffffff;
	}
	return (padding);
}

uint32_t	*ft_padding(t_env *e)
{
	uint32_t	*padding;
	int			emp;
	int			nb_blocks;

	nb_blocks = ((512 * e->multiple_de_512) / 32);
	padding = (uint32_t *)malloc(sizeof(uint32_t) * nb_blocks);
	padding = put_zero(padding, nb_blocks);
	ft_memcpy(padding, e->content, e->size);
	if (e->size % 4 == 0)
		padding[e->nbr_tab_content] = 0x00000080;
	else
	{
		emp = (e->size - (e->nbr_tab_content - 1) * 4) * 2;
		if (emp == 6)
			padding[e->nbr_tab_content - 1] += 0x80000000;
		else if (emp == 4)
			padding[e->nbr_tab_content - 1] += 0x00800000;
		else if (emp == 2)
			padding[e->nbr_tab_content - 1] += 0x00008000;
	}
	padding = add_size(padding, nb_blocks, e);
	return (padding);
}

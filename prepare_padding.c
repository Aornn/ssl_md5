/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:15:09 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/16 14:51:00 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		prepare_data(t_env *e)
{
	if (e->size_check == 1)
		e->size = ft_strlen(e->content);
	e->multiple_de_512 = ((e->size * 8 + 64) / 512) + 1;
	if (e->size % 4 == 0)
		e->nbr_tab_content = e->size / 4;
	else
		e->nbr_tab_content = e->size / 4 + 1;
}

uint32_t	*put_zero(uint32_t *padding, size_t nb_blocks)
{
	size_t i;

	i = 0;
	while (i < nb_blocks)
	{
		padding[i] = 0;
		i++;
	}
	return (padding);
}

uint32_t	*add_size(uint32_t *padding, size_t nb_blocks, t_env *e)
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

void		check_value_p(uint32_t *buf)
{
	if (buf == NULL)
	{
		ft_printf("Malloc error1\n");
		exit(1);
	}
}

uint32_t	*ft_padding(t_env *e)
{
	uint32_t	*padding;
	size_t		emp;
	size_t		nb_blocks;

	nb_blocks = ((512 * e->multiple_de_512) / 32);
	if ((padding = malloc(sizeof(uint32_t) * nb_blocks)) == NULL)
		check_value_p(padding);
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

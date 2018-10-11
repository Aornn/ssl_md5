/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:16:17 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_initialize_struct(t_info *info)
{
	SPEC = 0;
	ft_bzero(FLAGS, 7);
	WIDTH = 0;
	IS_PRECISION = 0;
	PRECISION = 0;
	MOD = NO_MOD;
	LEFT_Z = 0;
	LEFT_B = 0;
	RIGHT_B = 0;
	FILL_L = 0;
	FILL_R = 0;
	HEX_UPPER = 0;
}

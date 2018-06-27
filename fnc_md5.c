/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_md5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:22:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/06/27 15:19:38 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t str_bin_to_dec(const char* binstr) 
{          
	uint32_t result;
	int bit; 

	result = 0;
	bit = 0;
	while(binstr[bit] != '\0')
	{
		if(binstr[bit] == '1')
			result |= 1 ;
		bit++ ;
		if(binstr[bit] != '\0')
			result <<= 1 ;
	}
	return (result) ;
} 

uint32_t	rotate_left(uint32_t x, uint32_t c)
{
	
	return 	(((x) << (c)) | ((x) >> (32 - (c))));
}

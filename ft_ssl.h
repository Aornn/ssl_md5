/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:47:12 by rqueverd          #+#    #+#             */
/*   Updated: 2018/06/27 15:19:41 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

void	    concat_malloc(char **str, char *src);
char	    *print_bin_char(char c);
char	    *print_bin_int(int n);
void	    get_content(char **content, int fd, int height);
char	    *get_binary_content(int len_binary_content, char *content);
uint32_t	str_bin_to_dec(const char* binstr);
uint32_t	rotate_left(uint32_t v, uint32_t c);
int			get_height();
#endif

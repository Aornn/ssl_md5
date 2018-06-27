/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:22:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/06/27 18:39:23 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <inttypes.h>
/*
 **  Si le hash n'est pas bon ajouter les '\n' dans le *str concat_malloc
 */

static	uint32_t	g_r[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
	12, 17, 22, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static	uint32_t	g_k[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,0x698098d8, 0x8b44f7af,
	0xffff5bb1, 0x895cd7be,0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,0xd62f105d, 0x02441453,
	0xd8a1e681, 0xe7d3fbc8,0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,0xfffa3942, 0x8771f681,
	0x6d9d6122, 0xfde5380c,0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,0xd9d4d039, 0xe6db99e5,
	0x1fa27cf8, 0xc4ac5665,0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,0x6fa87e4f, 0xfe2ce6e0,
	0xa3014314, 0x4e0811a1,0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

void	ft_md5(char *binary_content)
{
	size_t		i;
	size_t		j;
	size_t		k;
	uint32_t	h[4];
	char		*words[16];
	char		line_32[33];
	uint32_t	a_b_c_d[4];
	uint32_t	temp;
	uint32_t	f_g[2];
	size_t		l;

	h[0] = 0x67452301;
	h[1] = 0xefcdab89;
	h[2] = 0x98badcfe;
	h[3] = 0x10325476;
	i = 0;
	j = 0;
	k = 0;

	while (i < ft_strlen(binary_content))
	{
		line_32[j] = binary_content[i];
		if ((i + 1) % 32 == 0)
		{
			line_32[32] = '\0';
			words[k] = ft_strnew(32);
			words[k] = ft_strcpy(words[k], line_32);
			j = -1;
			k ++;
		}
		if (k == 16)
		{	
			a_b_c_d[0] = h[0];
			a_b_c_d[1] = h[1];
			a_b_c_d[2] = h[2];
			a_b_c_d[3] = h[3];
			l = 0;
			while (l < 64)
			{
				if (l < 16)
				{
					f_g[0] = (a_b_c_d[1] & a_b_c_d[2]) | ((~a_b_c_d[1]) & a_b_c_d[3]);
					f_g[1] = l;
				}
				else if (l < 32)
				{
					f_g[0] = (a_b_c_d[3] & a_b_c_d[1]) | ((~a_b_c_d[3]) & a_b_c_d[2]);
					f_g[1] = (5 * l + 1) % 16;
				}
				else if (l < 48)
				{
					f_g[0] = a_b_c_d[1] ^ a_b_c_d[2] ^ a_b_c_d[3];
					f_g[1] = (3 * l + 5) % 16;          
				}
				else
				{
					f_g[0] = a_b_c_d[2] ^ (a_b_c_d[1] | (~a_b_c_d[3]));
					f_g[1] = (7 * l) % 16;
				}
				temp = a_b_c_d[3];
				a_b_c_d[3] = a_b_c_d[2];
				a_b_c_d[2] = a_b_c_d[1];
				a_b_c_d[1] = a_b_c_d[1] + rotate_left((a_b_c_d[0] + f_g[0] + g_k[l] + str_bin_to_dec(words[f_g[1]])), g_r[l]);
				a_b_c_d[0] = temp;

				l++;
			}
			h[0] += a_b_c_d[0];
			h[1] += a_b_c_d[1];
			h[2] += a_b_c_d[2];
			h[3] += a_b_c_d[3];
			k = 0;
		}
		j++;
		i++;
	}
	// printf("%08x%08x%08x%08x\n", h[0], h[1], h[2], h[3]);
	uint8_t *p;
    p=(uint8_t *)&h[0];
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h[1];
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h[2];
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
 
    p=(uint8_t *)&h[3];
    printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
    puts("");

}


int		main(void)
{
	char	*content;
	char	*binary_content;
	int		len_binary_content;
	char	*line;
	
	len_binary_content = 0;
	content = NULL;
	line = NULL;
	binary_content = NULL;
	int fd = open("test", O_RDONLY);
	get_content(&content, fd, get_height());
	ft_putstr(content);
	len_binary_content = ft_strlen(content) * 8;
	while (len_binary_content % 512 != 448)
		len_binary_content++;
	len_binary_content += 64;
	binary_content = get_binary_content(len_binary_content, content);
	line = print_bin_int(ft_strlen(content) * 8);
	binary_content = ft_strcat(binary_content, line);
	ft_md5(binary_content);
	// free(content);
	// free(line);
	// free(binary_content);
	// ft_putendl("\nMD5(test)= 5d41402abc4b2a76b9719d911017c592");
}

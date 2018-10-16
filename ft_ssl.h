/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:21:14 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/16 16:52:20 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "libft/includes/libft.h"
# include "fcntl.h"
# include "unistd.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/stat.h>
# define OPT_R 1
# define OPT_Q 2
# define OPT_S 4
# define OPT_P 8
# define OPT_F 16

static	uint32_t	g_r[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
	12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11,
	16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10,
	15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static	uint32_t	g_k[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af,
	0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453,
	0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681,
	0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5,
	0x1fa27cf8, 0xc4ac5665, 0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0,
	0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static	uint32_t	g_sha256_k[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf,
	0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98,
	0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
	0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
	0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8,
	0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85,
	0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e,
	0x92722c85, 0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
	0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c08, 0x2748774c,
	0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 0x748f82ee,
	0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
	0xc67178f2};

typedef struct		s_env
{
	char		*content;
	size_t		multiple_de_512;
	size_t		nbr_tab_content;
	size_t		size;
	size_t		tmp_size;
	size_t		i;
	int			fd;
	int			first_p;
	int			index;
	int			file_check;
	int			option;
	size_t		size_check;
	int			len_pos_p;
	int			fail_file;
	int			check_r;
	int			check_p;
	int			check_q;
	int			check_f_p;
	int			check_files_p;
}					t_env;

typedef enum		e_cmd
{
	md5,
	sha256,
	sha224,
	nbr_cmd
}					t_cmd;

typedef struct		s_env_md5
{
	uint32_t	i;
	uint64_t	l;
	uint32_t	h0;
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	a_b_c_d[4];
	uint64_t	f_g[2];
	uint32_t	temp;
}					t_env_md5;

typedef struct		s_env_sha256
{
	uint32_t	h1;
	uint32_t	h2;
	uint32_t	h3;
	uint32_t	h4;
	uint32_t	h5;
	uint32_t	h6;
	uint32_t	h7;
	uint32_t	h8;
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
	uint32_t	w[64];
	uint32_t	s0;
	uint32_t	maj;
	uint32_t	s_0;
	uint32_t	s_1;
	uint32_t	temp2;
	uint32_t	temp1;
	uint32_t	s1;
	uint32_t	ch;
	uint64_t	nb_blocks;
}					t_env_sha256;

typedef	void		(*t_select_hash)(uint32_t *padding, t_env e);

uint32_t			right_rotate(uint32_t n, uint32_t d);
uint32_t			uint32_btl(uint32_t val);
uint32_t			rotate_left(uint32_t v, uint32_t c);
char				*read_file(int fd, t_env *e);
uint32_t			reverse_bits(uint32_t value);
void				ft_md5(uint32_t *padding, t_env e);
void				ft_sha256(uint32_t *padding, t_env e);
void				stage1 (t_env_md5 *e_md5);
void				stage2 (t_env_md5 *e_md5);
void				stage3 (t_env_md5 *e_md5);
void				stage4 (t_env_md5 *e_md5);
void				save_arg(t_env *e, int argc, char **argv);
int					index_fnc(char *algo);
uint32_t			*ft_padding(t_env *e);
void				prepare_data(t_env *e);
void				wrong_opt(char **argv, int i);
void				is_directory(char **argv, int i, t_env *e);
void				no_file(char **argv, int i, t_env *e);
void				init_var_main(t_env *e, int argc, char **argv,
		t_select_hash *hash_choose);
void				create_hash_by_fd(t_env *e, int fd,
		t_select_hash *hash_choose, int i);
void				create_hash_by_s(t_env *e, char *in, char *argv,
		t_select_hash *hash_choose);
void				manage_q(t_env *e, t_select_hash *hash_choose);
void				manage_r(t_env *e, t_select_hash *hash_choose);
void				init_var_sha256(t_env_sha256 *e, t_env e_struc,
		uint64_t *i, uint64_t *j);
void				ft_argc_2(t_env *e, int argc, t_select_hash *hash_choose);
void				disp_sha256(t_env_sha256 e, t_env e_struc);
void				manage_p(t_env *e, t_select_hash *hash_choose);
void				check_value_r(char *buf, char *output, int fd);
#endif

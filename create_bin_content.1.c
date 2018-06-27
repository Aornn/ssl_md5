/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bin_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:22:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/06/27 17:25:15 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	get_content(char **content, int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		concat_malloc(content, line);
		free(line);
	}
}

void	concat_malloc(char **str, char *src)
{
	char	*final;
	int		size;

	size = 0;
	final = NULL;
	if (*str != NULL)
	{
		size = ft_strlen(*str) + ft_strlen(src) + 1;
		final = malloc(size * sizeof(char));
		final = ft_strcpy(final, *str);
		final = ft_strcat(final, src);
		free(*str);
		*str = malloc((ft_strlen(final) + 1) * sizeof(char));
		*str = strcpy(*str, final);
	}
	else
	{
		*str = malloc((ft_strlen(src) + 1) * sizeof(char));
		*str = strcpy(*str, src);
	}
	free(final);
}

char	*print_bin_char(char c)
{
	int		i;
	char	*oct;

	i = 7;
	oct = malloc(9 * sizeof(char));
	while (i >= 0)
	{
		oct[7 - i] = (c & (1 << i)) ? '1' : '0';
		i--;
	}
	oct[8] = '\0';
	return (oct);
}

char	*print_bin_int(int n)
{
	
	int		c;
	int		k;
	char	*output;

	c = 0;
	output = ft_memalloc(65 * sizeof(char));
	while (c <= 63)
	{
		k = n >> c;
		if (k & 1)
			output[c] = '1';
		else
			output[c] = '0';
		c++;
	}
	output[64] = '\0';
	output = ft_strrev(output);
	return (output);
}

char	*get_binary_content(int len_binary_content, char *content)
{
	char	*binary_content;
	char	*line;
	size_t	i;

	i = 0;
	binary_content = malloc((len_binary_content) * sizeof(char));
	while ((int)i < len_binary_content - 64)
	{
		if (i < ft_strlen(content))
		{
			line = print_bin_char(content[i]);
			binary_content = ft_strcat(binary_content, line);
			free(line);
		}
		else if (i == ft_strlen(content))
		{
			i = i * 8;
			binary_content[i] = '1';
		}
		else
			binary_content[i] = '0';
		i++;
	}
	binary_content[len_binary_content + 64] = '\0';
	return (binary_content);
}
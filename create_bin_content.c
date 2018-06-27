/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bin_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:22:00 by rqueverd          #+#    #+#             */
/*   Updated: 2018/06/27 18:37:49 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int get_height()
{
	int fd = open("test", O_RDONLY);
	char *line;
	int i = -1;

	while (get_next_line(fd, &line) == 1)
		i++;
	return (i);
}

void	get_content(char **content, int fd, int height)
{
	char	*line = NULL;
	int ret;
	int j = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		concat_malloc(content, line);
		if(j == height)
		{
			*content = ft_strjoin(*content, "\n");
		}
		free(line);
		j++;
	}
}

void	concat_malloc(char **str, char *src)
{
	if (*str != NULL)
	{
		*str = ft_strjoin(*str, "\n");
		if (ft_strlen(src) > 0)
			*str = ft_strjoin(*str, src);
	}
	else
	{
		*str = ft_strjoin("", src);
	}
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

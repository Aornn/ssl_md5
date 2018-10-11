/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:41:35 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_start_w(char const *s, size_t index, char c)
{
	if (index == 0 && s[index] != c)
		return (1);
	if (s[index] != c && s[index - 1] == c)
		return (1);
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**ret;

	i = 0;
	k = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_count_w(s, c) + 1)))
		return (NULL);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		j = 0;
		if (is_start_w(s, i, c))
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			ret[k] = ft_strsub(s, i, j);
			k++;
		}
		i++;
	}
	ret[k] = 0;
	return (ret);
}

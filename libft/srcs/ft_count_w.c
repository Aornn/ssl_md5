/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:15:15 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_w(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else if (s[i] == c)
		{
			n++;
			while (s[i] == c)
				i++;
		}
	}
	if (s[i] == '\0' && s[i - 1] != c)
		n++;
	return (n);
}

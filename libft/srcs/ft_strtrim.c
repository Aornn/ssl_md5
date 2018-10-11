/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:26 by rqueverd          #+#    #+#             */
/*   Updated: 2018/10/10 11:43:12 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	int		k;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	k = 0;
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		start++;
		if (s[start] == '\0')
			k = 1;
	}
	while (k == 0 && (s[end - 1] == ' ' || s[end - 1] == '\n' ||
				s[end - 1] == '\t'))
		end--;
	ret = ft_strnew(end - start);
	if (!ret)
		return (NULL);
	return (ft_strncpy(ret, &(s)[start], end - start));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:22:43 by rqueverd          #+#    #+#             */
/*   Updated: 2016/11/14 15:01:37 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size_s;
	char	*dest;

	size_s = 0;
	if (s == NULL)
		return (NULL);
	while (s[size_s])
		size_s++;
	dest = (char*)malloc(size_s + 1 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = (*f)(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:37:54 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/24 14:32:00 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	count;

	count = 0;
	if (!s || start + len > ft_strlen(s))
		return (NULL);
	if ((res = ft_strnew(len)))
	{
		while (len)
		{
			res[count] = s[start];
			count++;
			start++;
			len--;
		}
		res[count] = '\0';
	}
	return (res);
}

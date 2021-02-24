/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:32:09 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/24 17:54:38 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int x;
	int y;

	if (*needle == '\0')
		return ((char *)haystack);
	x = 0;
	while (haystack[x] != '\0')
	{
		if (haystack[x] == needle[0])
		{
			y = 1;
			while (haystack[x + y] == needle[y] && needle[y] != '\0')
				y++;
			if (needle[y] == '\0')
				return ((char *)(haystack + x));
		}
		x++;
	}
	return (NULL);
}

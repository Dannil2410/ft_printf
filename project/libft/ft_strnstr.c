/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:26:21 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 19:43:24 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t x;
	size_t y;

	if (*need == '\0')
		return ((char *)hay);
	x = 0;
	while (hay[x] && (x < len))
	{
		if (hay[x] == need[0])
		{
			y = 1;
			while (hay[x + y] == need[y]
					&& need[y] != '\0' && (x + y < len))
				y++;
			if (need[y] == '\0')
				return ((char *)(hay + x));
		}
		x++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:08 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/24 14:27:32 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t x;
	size_t y;
	size_t result;

	x = 0;
	while (dst[x])
		x++;
	result = 0;
	while (src[result])
		result++;
	if (size <= x)
		result = result + size;
	else
		result = result + x;
	y = 0;
	while (src[y] && (x + 1 < size))
	{
		dst[x] = src[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (result);
}

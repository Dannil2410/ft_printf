/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:30:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/24 14:21:32 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	temp;
	unsigned char	*result;
	unsigned char	*temp2;
	size_t			count;

	result = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	temp = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		result[count] = temp2[count];
		count++;
		if (temp == temp2[count - 1])
			return (result + count);
	}
	return (NULL);
}

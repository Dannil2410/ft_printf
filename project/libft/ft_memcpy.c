/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:49:46 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/27 16:04:05 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *temp1;
	unsigned char *temp2;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	while (n)
	{
		*temp1++ = *temp2++;
		n--;
	}
	return (dst);
}

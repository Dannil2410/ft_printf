/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:01:32 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/27 16:40:06 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *temp1;
	unsigned char *temp2;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	if (temp1 < temp2)
		while (len)
		{
			*temp1++ = *temp2++;
			len--;
		}
	else
	{
		temp1 = temp1 + len;
		temp2 = temp2 + len;
		while (len)
		{
			*--temp1 = *--temp2;
			len--;
		}
	}
	return (dst);
}

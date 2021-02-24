/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:14:01 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 17:37:31 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *result;
	unsigned char temp;

	result = (unsigned char *)s;
	temp = (unsigned char)c;
	while (n)
	{
		if (*result == temp)
			return (result);
		result++;
		n--;
	}
	return (NULL);
}

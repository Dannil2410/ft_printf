/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:19:34 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 17:38:27 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			count;

	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	if (!temp1 && !temp2 && !n)
		return (0);
	count = 0;
	while (count < n)
	{
		if (temp1[count] != temp2[count])
			return (temp1[count] - temp2[count]);
		count++;
	}
	return (0);
}

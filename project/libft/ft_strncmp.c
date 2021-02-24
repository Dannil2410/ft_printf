/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:39:41 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/05 16:49:04 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t count;

	if (n == 0)
		return (0);
	count = 0;
	while (s1[count] == s2[count] && (count < (n - 1)))
	{
		count++;
		if (s1[count] == '\0' && s2[count] == '\0')
			return (0);
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}

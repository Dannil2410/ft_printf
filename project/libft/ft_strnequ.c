/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:04 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/25 19:01:14 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t count;

	count = 0;
	if (s1 && s2)
	{
		while (s1[count] == s2[count] && s1[count] && s2[count] && count < n)
			count++;
		if ((s1[count] - s2[count] != 0) && (count < n))
			return (0);
		return (1);
	}
	return (0);
}

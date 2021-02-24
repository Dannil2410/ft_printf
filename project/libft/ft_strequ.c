/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:28:00 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/25 19:04:50 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int count;

	if (s1 && s2)
	{
		count = 0;
		while (s1[count] && s2[count] && s1[count] == s2[count])
			count++;
		if (s1[count] - s2[count] != 0)
			return (0);
		return (1);
	}
	return (0);
}

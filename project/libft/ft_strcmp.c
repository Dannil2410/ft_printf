/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:37:24 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/05 16:42:57 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t check;

	check = 0;
	while (s1[check] == s2[check])
	{
		check++;
		if (s1[check] == '\0' && s2[check] == '\0')
			return (0);
	}
	return ((unsigned char)s1[check] - (unsigned char)s2[check]);
}

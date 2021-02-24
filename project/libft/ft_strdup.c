/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:59:37 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/05 16:54:28 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		length;
	int		check;

	length = 0;
	while (s1[length])
		length++;
	if (!(copy = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	check = 0;
	while (s1[check])
	{
		copy[check] = s1[check];
		check++;
	}
	copy[check] = '\0';
	return (copy);
}

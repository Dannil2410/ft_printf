/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:55:55 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 18:15:26 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	length;
	int		x;
	int		y;

	length = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	x = 0;
	while (s1[x])
	{
		res[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y])
	{
		res[x + y] = s2[y];
		y++;
	}
	res[x + y] = '\0';
	return (res);
}

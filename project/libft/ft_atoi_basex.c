/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_basex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:20:28 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/03 18:51:08 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isnothing(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

static int		ft_letnum(char c, int base)
{
	char *elem1;
	char *elem2;

	elem1 = "0123456789abcdef";
	elem2 = "0123456789ABCDEF";
	while (base--)
		if ((elem1[base] == c) || (elem2[base] == c))
			return (1);
	return (0);
}

static int		ft_recogn(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int				ft_atoi_basex(const char *str, int str_base)
{
	int result;
	int flag;

	result = 0;
	while (ft_isnothing(*str))
		str++;
	flag = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_letnum(*str, str_base))
		result = result * str_base + ft_recogn(*str++);
	return (result * flag);
}

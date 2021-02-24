/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:37:13 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/03 18:11:42 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(long int n)
{
	int length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char			*ft_itoa(int n)
{
	int		length;
	int		flag;
	char	*result;

	flag = (n < 0) ? -1 : 1;
	length = ft_length(n);
	result = ((char *)malloc(sizeof(char) * (length + 1)));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	length = length - 1;
	while (length >= 0)
	{
		result[length] = '0' + ft_modul(n % 10);
		n = ft_modul(n / 10);
		length--;
	}
	if (flag == -1)
		result[0] = '-';
	return (result);
}

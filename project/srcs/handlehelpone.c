/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelpone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:37:48 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/02 11:49:03 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_baseoau(unsigned long long int number, int base, char temp)
{
	char	*r;
	int		c;

	c = baser(number, base);
	if (!(r = (char*)ft_memalloc(c + 1)))
		return (NULL);
	if (number == 0)
		r[0] = '0';
	while (number)
	{
		r[--c] = (number % base > 9) ? (number % base - 10 + temp) :
			(number % base + '0');
		number /= base;
	}
	return (r);
}

char	signcheck(t_info *base, long long int number)
{
	char	sign;

	if (base->fspace)
		sign = ' ';
	else
		sign = '+';
	if (number < 0)
	{
		sign = '-';
		base->negativ = 1;
	}
	return (sign);
}

int		printfloat(t_info *base, char *big, char *small, char sign)
{
	int pflengthf;

	pflengthf = lengthfprintf(base, big);
	structfcheck(base, pflengthf, 1);
	if (base->fspace || base->negativ || base->fplus)
		write(1, &sign, 1);
	structfcheck(base, pflengthf, 2);
	write(1, big, ft_strlen(big));
	if (base->fhash || base->precs)
		write(1, ".", 1);
	write(1, small, ft_strlen(small));
	structfcheck(base, pflengthf, 3);
	if (sign == '-')
		pflengthf++;
	return (pflengthf);
}

int		baser(unsigned long long number, int base)
{
	int c;

	c = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= base;
		c++;
	}
	return (c);
}

char	*ft_baseoa(long long int number)
{
	char	*r;
	int		c;

	if (number < 0)
		c = baser(-number, 10);
	else
		c = baser(number, 10);
	if (!(r = (char*)ft_memalloc(c + 1)))
		return (NULL);
	if (number == 0)
		r[0] = '0';
	while (number)
	{
		if (number > 0)
			r[--c] = (number % 10) + '0';
		else
			r[--c] = -(number % 10) + '0';
		number /= 10;
	}
	return (r);
}

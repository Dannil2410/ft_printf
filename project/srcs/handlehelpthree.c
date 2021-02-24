/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelpthree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:38:04 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 19:40:50 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		flaghelpf(t_info *base)
{
	base->point = 1;
	base->precs = 0;
	base->fhash = 0;
	base->fzero = 0;
}

long double	smallfloathelp(char *big)
{
	long double number;

	number = 0;
	while (*big)
	{
		number = 10 * number;
		number = (long double)(*big - '0') + number;
		big++;
	}
	return (number);
}

char		*smallfloat(t_info *base, long double number, int precs, char *big)
{
	char		*r;
	int			c;
	long double	res;

	c = 0;
	number = number < 0 ? -number : number;
	number -= smallfloathelp(big);
	if (!(r = (char*)ft_memalloc(precs + 1)))
		return (NULL);
	while (c < precs)
	{
		number = 10 * number;
		res = base->modif == 5 ? number + 0.000001 : number;
		if (number > 0 && ((int)res == (int)number))
			r[c++] = (int)number + '0';
		else if (number > 0 && !((int)res == (int)number))
			r[c++] = ((int)res == 10) ? '0' : (int)number + 1 + '0';
		else
			r[c++] = '0';
		number -= (int)number;
	}
	return (r);
}

int			lengthfloat(long double number)
{
	int c;

	c = 0;
	while (number > 1)
	{
		number /= 10;
		c++;
	}
	if (c > 1)
		return (c);
	else
		return (1);
}

char		*bigfloat(long double number)
{
	char		*r;
	char		*rtemp;
	long double	temp;
	int			c;
	int			i;

	c = lengthfloat(number);
	if (!(r = (char*)ft_memalloc(c + 1)))
		return (NULL);
	rtemp = r;
	while (c)
	{
		i = c - 1;
		temp = number;
		while (i--)
			temp /= 10;
		*rtemp++ = (int)temp + '0';
		temp = (int)temp;
		while (++i < c - 1)
			temp *= 10;
		number -= temp;
		c--;
	}
	return (r);
}

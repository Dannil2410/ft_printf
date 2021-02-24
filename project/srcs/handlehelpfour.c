/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelpfour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:37:34 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/02 10:40:47 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		structfcheck(t_info *base, int pflengthf, int temp)
{
	if (!base->fzero && (base->width > pflengthf))
	{
		if (base->fminus && (temp == 3))
			putlenchar(base->width - pflengthf, ' ');
		else if (!base->fminus && (temp == 1))
			putlenchar(base->width - pflengthf, ' ');
	}
	if (temp == 2)
	{
		if (base->fzero && base->width)
		{
			if (base->width > pflengthf)
				putlenchar(base->width - pflengthf, '0');
		}
	}
}

int			lengthfprintf(t_info *base, char *big)
{
	int pflengthf;

	if (base->nan || base->inf)
		pflengthf = 3;
	else
		pflengthf = ft_strlen(big) + base->precs;
	if (base->precs > 0 || base->fhash)
		pflengthf++;
	if (base->fspace || base->fplus)
		pflengthf++;
	return (pflengthf);
}

long double	precisioner(int precs)
{
	long double number;

	number = 1;
	while (precs > 0)
	{
		number = 10 * number;
		precs--;
	}
	while (precs < 0)
	{
		number /= 10;
		precs++;
	}
	return (number);
}

long double	rounder(t_info *base, long double number)
{
	long double	temp;
	char		*big;
	char		*small;

	if (number < 0)
		number = -number;
	temp = number * precisioner(base->precs);
	big = bigfloat(temp);
	small = smallfloat(base, temp, base->precs, big);
	temp -= smallfloathelp(big);
	free(big);
	if (temp > 0.5 || (temp == 0.5 && ((big[ft_strlen(big) - 1] - '0') % 2)))
		number = 0.5 * precisioner(-base->precs) + number;
	return (number);
}

void		flagcheckf(t_info *base, long double number)
{
	if (!(number == number))
	{
		flaghelpf(base);
		base->nan = 1;
		base->fplus = 0;
	}
	if ((number == (1.0 / 0.0)) || (number == -(1.0 / 0.0)))
	{
		flaghelpf(base);
		base->inf = 1;
		if (number == -(1.0 / 0))
			base->negativ = 1;
	}
	if (base->fplus)
		base->fspace = 0;
	if (base->fminus)
		base->fzero = 0;
	if (!base->point)
	{
		base->point = 1;
		base->precs = 6;
	}
}

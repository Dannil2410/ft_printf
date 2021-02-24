/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelptwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:38:21 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/02 10:52:05 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char					signcheckf(t_info *base, long double number)
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

void					freetime(t_info *base, char *big, char *small)
{
	if (!base->inf && !base->nan)
	{
		free(big);
		free(small);
	}
}

long double				modiftransformf(t_info *base, va_list args)
{
	long double number;

	if (base->modif == 5)
		number = va_arg(args, long double);
	else
		number = (double)va_arg(args, double);
	return (number);
}

unsigned long long int	modiftransformu(t_info *base, va_list args)
{
	unsigned long long int number;

	if (base->modif == 1)
		number = (unsigned short int)va_arg(args, unsigned int);
	else if (base->modif == 2)
		number = (unsigned char)va_arg(args, unsigned int);
	else if (base->modif == 3)
		number = va_arg(args, unsigned long int);
	else if (base->modif == 4)
		number = va_arg(args, unsigned long long int);
	else
		number = (unsigned int)va_arg(args, unsigned int);
	return (number);
}

void					flagcheck(t_info *base)
{
	if (base->fminus)
		base->fzero = 0;
	if (base->point)
		base->fzero = 0;
	if (base->fplus)
		base->fspace = 0;
}

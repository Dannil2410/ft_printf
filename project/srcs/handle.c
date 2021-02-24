/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:36:47 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 17:41:52 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	handleo(t_info *base, va_list args)
{
	unsigned long long int	number;
	char					*r;

	number = modiftransformu(base, args);
	r = ft_baseoau(number, 8, 0);
	if (base->fhash)
	{
		base->point = 1;
		if (number)
		{
			if (base->precs < (int)ft_strlen(r) + 1)
				base->precs = ft_strlen(r) + 1;
		}
		else
		{
			if (base->precs < 1)
				base->precs = 1;
		}
	}
	return (putlencharu(base, number, r, NULL));
}

int	handlex(t_info *base, va_list args)
{
	unsigned long long int	number;
	char					*r;
	char					*temp;
	char					caser;

	number = modiftransformu(base, args);
	if (base->conv == 4)
		caser = 'a';
	else
		caser = 'A';
	r = ft_baseoau(number, 16, caser);
	if (base->fhash && number)
	{
		if (base->conv == 4)
			temp = "0x";
		else
			temp = "0X";
		base->temp = 1;
	}
	if (base->temp)
		return (putlencharu(base, number, r, temp));
	else
		return (putlencharu(base, number, r, NULL));
}

int	handlepct(t_info *base)
{
	if (base->width && !base->fminus)
	{
		if (base->fzero)
			putlenchar(base->width - 1, '0');
		else
			putlenchar(base->width - 1, ' ');
	}
	write(1, "%", 1);
	if (base->width && base->fminus)
		putlenchar(base->width - 1, ' ');
	if (base->width)
		return (base->width);
	else
		return (1);
}

int	handlef(t_info *base, va_list args)
{
	long double	number;
	char		sign;
	char		*big;
	char		*small;
	int			pflengthf;

	small = "";
	number = modiftransformf(base, args);
	flagcheckf(base, number);
	sign = signcheckf(base, number);
	if (!base->inf && !base->nan)
	{
		number = rounder(base, number);
		big = bigfloat(number);
		small = smallfloat(base, number, base->precs, big);
	}
	else
		big = base->inf ? "inf" : "nan";
	pflengthf = printfloat(base, big, small, sign);
	freetime(base, big, small);
	if (base->width > pflengthf)
		return (base->width);
	else
		return (pflengthf);
}

int	handlet(t_info *base, va_list args)
{
	int	date;
	int	length;
	int flag;

	flag = 0;
	if (!base->modif)
	{
		date = (int)va_arg(args, int);
		length = ft_time(date);
		return (length);
	}
	else
	{
		date = (int)va_arg(args, int);
		if (base->modif == 9)
			flag = 1;
		length = ft_nbr_of_year(date, flag);
		return (length);
	}
}

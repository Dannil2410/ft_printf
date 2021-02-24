/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:39:00 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 17:23:03 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		handlenopct(const char *format)
{
	char	*temp;
	int		length;

	temp = ft_strchr(format, '%');
	if (temp)
		length = temp - format;
	else
		length = ft_strlen(format);
	write(1, format, length);
	return (length);
}

int		handleall(t_info *base, va_list args)
{
	static int (*handlesall[12])(t_info *base, va_list args) = {
		&handled,
		&handleo,
		&handleu,
		&handlex,
		&handlex,
		&handlef,
		&handlec,
		&handles,
		&handlep,
		&handlet
	};
	static int (*handlepercentage)(t_info *base) = &handlepct;

	if (base->conv == 11)
		return (handlepercentage(base));
	return ((handlesall[base->conv - 1](base, args)));
}

int		parser(const char *format, t_info *base, va_list args)
{
	const char *temp;

	temp = format;
	format = parsef(format, base);
	format = parsew(format, base, args);
	format = parsep(format, base, args);
	format = format + parsem(format, base);
	format = parsec(format, base);
	return (format - temp);
}

void	initstruct(t_info *base, int *major)
{
	base->fhash = 0;
	base->fzero = 0;
	base->fminus = 0;
	base->fplus = 0;
	base->fspace = 0;
	base->width = 0;
	base->point = 0;
	base->precs = 0;
	base->modif = 0;
	base->conv = 0;
	base->valid = 0;
	base->temp = 0;
	base->negativ = 0;
	base->nan = 0;
	base->inf = 0;
	*major = 0;
}

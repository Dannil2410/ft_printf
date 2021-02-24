/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:02:44 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 18:39:53 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*parsec(const char *format, t_info *base)
{
	static char	temp[] = "diouxXfcspt%";
	char		*res;

	if ((res = ft_strchr(temp, *format)) && *format)
	{
		res[0] == 'd' ? base->conv = 1 : 0;
		res[0] == 'i' ? base->conv = 1 : 0;
		res[0] == 'o' ? base->conv = 2 : 0;
		res[0] == 'u' ? base->conv = 3 : 0;
		res[0] == 'x' ? base->conv = 4 : 0;
		res[0] == 'X' ? base->conv = 5 : 0;
		res[0] == 'f' ? base->conv = 6 : 0;
		res[0] == 'c' ? base->conv = 7 : 0;
		res[0] == 's' ? base->conv = 8 : 0;
		res[0] == 'p' ? base->conv = 9 : 0;
		res[0] == 't' ? base->conv = 10 : 0;
		res[0] == '%' ? base->conv = 11 : 0;
		base->valid = 1;
		format++;
	}
	return (format);
}

int			parsem(const char *format, t_info *base)
{
	static char	temp[] = "hlLUDyYr";
	char		*res;

	if (ft_strnstr(format, "ll", 2) || ft_strnstr(format, "hh", 2))
	{
		if (ft_strnstr(format, "ll", 2))
			base->modif = 4;
		else if (ft_strnstr(format, "hh", 2))
			base->modif = 2;
		return (2);
	}
	else if ((res = ft_strchr(temp, *format)) && *format)
	{
		res[0] == 'h' ? base->modif = 1 : 0;
		res[0] == 'l' ? base->modif = 3 : 0;
		res[0] == 'L' ? base->modif = 5 : 0;
		res[0] == 'U' ? base->modif = 6 : 0;
		res[0] == 'D' ? base->modif = 7 : 0;
		res[0] == 'y' ? base->modif = 8 : 0;
		res[0] == 'Y' ? base->modif = 9 : 0;
		res[0] == 'r' ? base->modif = 10 : 0;
		return (1);
	}
	return (0);
}

const char	*parsep(const char *format, t_info *base, va_list args)
{
	int extra;

	if (*format == '.')
	{
		base->point = 1;
		format++;
		while (*format >= '0' && *format <= '9')
		{
			if (!(base->precs))
				base->precs = ft_atoi(format);
			format++;
		}
		if (*format == '*')
		{
			if (!(base->precs))
				base->precs = va_arg(args, int);
			else
				extra = va_arg(args, int);
			if (base->precs < 0)
				base->point = 0;
			format++;
		}
	}
	return (format);
}

const char	*parsew(const char *format, t_info *base, va_list args)
{
	int star;
	int count;

	star = 0;
	count = 0;
	while (count == 0 || count == 1)
	{
		if (*format == '*')
		{
			star = parsestar(star, base, args);
			format++;
		}
		while ((*format >= '0' && *format <= '9') && count == 0)
		{
			if (!(base->width) || star)
				base->width = ft_atoi(format);
			format++;
		}
		count++;
	}
	return (format);
}

const char	*parsef(const char *format, t_info *base)
{
	char	*temp;
	int		res;

	temp = "#0-+ ";
	res = 1;
	while (*format && res)
	{
		res = checksym(format, temp);
		if (res == 1)
		{
			if (*format == '#')
				base->fhash = 1;
			else if (*format == '0')
				base->fzero = 1;
			else if (*format == '-')
				base->fminus = 1;
			else if (*format == '+')
				base->fplus = 1;
			else if (*format == ' ')
				base->fspace = 1;
			format++;
		}
	}
	return (format);
}

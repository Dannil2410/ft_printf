/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 06:01:47 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/02 11:48:05 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_info	base;
	int		major;
	int		minor;

	initstruct(&base, &major);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = format + parser(format + 1, &base, args) + 1;
			if (base.valid == 1)
				major = handleall(&base, args) + major;
			ft_bzero(&base, sizeof(base));
		}
		else
		{
			minor = handlenopct(format);
			format = format + minor;
			major = minor + major;
		}
	}
	va_end(args);
	return (major);
}

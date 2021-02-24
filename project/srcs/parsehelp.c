/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsehelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:36:28 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/02 11:40:56 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parsestar(int star, t_info *base, va_list args)
{
	int	extra;

	if (!(base->width) || star == 0)
	{
		base->width = va_arg(args, int);
		if (base->width < 0)
		{
			base->fminus = 1;
			base->width = -base->width;
		}
		return (1);
	}
	else
	{
		extra = va_arg(args, int);
		return (star);
	}
}

int		checksym(const char *format, char *temp)
{
	int	index;

	index = 0;
	while (temp[index])
	{
		if (*format == temp[index])
			return (1);
		index++;
	}
	return (0);
}

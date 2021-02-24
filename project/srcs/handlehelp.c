/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:37:04 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/02 11:46:06 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long int	modiftransform(t_info *base, va_list args)
{
	long long int number;

	if (base->modif == 1)
		number = (short int)va_arg(args, int);
	else if (base->modif == 2)
		number = (char)va_arg(args, int);
	else if (base->modif == 3)
		number = va_arg(args, long int);
	else if (base->modif == 4)
		number = va_arg(args, long long int);
	else
		number = (int)va_arg(args, int);
	return (number);
}

void			structcheck(t_info *base, int length, int pflength, int temp)
{
	if (!base->fzero && (base->width > pflength))
	{
		if (base->fminus && (temp == 3))
			putlenchar(base->width - pflength, ' ');
		else if (!base->fminus && (temp == 1))
			putlenchar(base->width - pflength, ' ');
	}
	if (temp == 2)
	{
		if (base->point)
		{
			if (base->precs > length)
				putlenchar(base->precs - length, '0');
		}
		else if (base->fzero && base->width)
		{
			if (base->width > pflength)
				putlenchar(base->width - pflength, '0');
		}
	}
}

int				lengthprintf(t_info *base, int length, char *temp)
{
	int pflength;

	if (base->point && (base->precs > length))
		pflength = base->precs;
	else
		pflength = length;
	if ((base->conv == 1) && (base->fspace || base->fplus || base->negativ))
		pflength = pflength + 1;
	if (base->temp)
		pflength = ft_strlen(temp) + pflength;
	return (pflength);
}

char			*ft_sixteenoa(void *pointer, char temp)
{
	char				*r;
	unsigned long long	n;
	int					c;

	n = (unsigned long long)pointer;
	c = 0;
	while (n != 0)
	{
		n /= 16;
		c++;
	}
	n = (unsigned long long)pointer;
	if (n == 0)
		c = 1;
	if (!(r = (char*)ft_memalloc(c + 1)))
		return (NULL);
	if (pointer == NULL)
		r[0] = '0';
	while (n)
	{
		r[--c] = (n % 16 > 9) ? (n % 16 - 10 + temp) : (n % 16 + '0');
		n /= 16;
	}
	return (r);
}

void			putlenchar(int length, char temp)
{
	while (length != 0)
	{
		write(1, &temp, 1);
		length--;
	}
}

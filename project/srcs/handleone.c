/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:38:33 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 16:51:59 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	handlec(t_info *base, va_list args)
{
	char temp;

	temp = va_arg(args, int);
	if (base->width && !(base->fminus))
	{
		if (base->fzero)
			putlenchar(base->width - 1, '0');
		else
			putlenchar(base->width - 1, ' ');
	}
	write(1, &temp, 1);
	if (base->width && base->fminus)
		putlenchar(base->width - 1, ' ');
	if (base->width)
		return (base->width);
	else
		return (1);
}

int	handles(t_info *base, va_list args)
{
	char	*temp;
	int		length;

	temp = va_arg(args, char*);
	if (temp)
		length = ft_strlen(temp);
	else
		length = 6;
	if (base->point && (base->precs < length))
		length = base->precs;
	if (base->width && !(base->fminus) && (base->width > length))
	{
		if (base->fzero)
			putlenchar(base->width - length, '0');
		else
			putlenchar(base->width - length, ' ');
	}
	temp ? writestr(temp, length, base->modif) : write(1, "(null)", length);
	if (base->width && base->fminus && (base->width > length))
		putlenchar(base->width - length, ' ');
	if (base->width > length)
		return (base->width);
	else
		return (length);
}

int	handlep(t_info *base, va_list args)
{
	void	*pointer;
	char	*r;
	int		length;
	int		pflength;

	pointer = va_arg(args, void*);
	r = ft_sixteenoa(pointer, 'a');
	base->temp = 1;
	if (base->point && !base->precs && !pointer)
		length = 0;
	else
		length = ft_strlen(r);
	pflength = lengthprintf(base, length, "0x");
	structcheck(base, length, pflength, 1);
	write(1, "0x", 2);
	structcheck(base, length, pflength, 2);
	write(1, r, length);
	structcheck(base, length, pflength, 3);
	free(r);
	if (base->width > pflength)
		return (base->width);
	else
		return (pflength);
}

int	handled(t_info *base, va_list args)
{
	long long int	number;
	char			sign;
	char			*r;
	int				length;
	int				pflength;

	length = 0;
	number = modiftransform(base, args);
	r = ft_baseoa(number);
	flagcheck(base);
	sign = signcheck(base, number);
	if (!(base->point && !base->precs && (number == 0)))
		length = ft_strlen(r);
	pflength = lengthprintf(base, length, NULL);
	structcheck(base, length, pflength, 1);
	if (number < 0 || base->fplus || base->fspace)
		write(1, &sign, 1);
	structcheck(base, length, pflength, 2);
	write(1, r, length);
	structcheck(base, length, pflength, 3);
	free(r);
	if (base->width > pflength)
		return (base->width);
	else
		return (pflength);
}

int	handleu(t_info *base, va_list args)
{
	unsigned long long int	number;
	char					*r;

	number = modiftransformu(base, args);
	r = ft_baseoau(number, 10, 0);
	return (putlencharu(base, number, r, NULL));
}

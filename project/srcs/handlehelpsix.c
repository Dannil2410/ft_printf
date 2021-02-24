/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelpsix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:29:20 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 20:05:07 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	putlencharu(t_info *base, unsigned long long number, char *r, char *temp)
{
	int length;
	int pflength;

	flagcheck(base);
	length = (base->point && !base->precs && (number == 0)) ? 0 : ft_strlen(r);
	pflength = lengthprintf(base, length, temp);
	structcheck(base, length, pflength, 1);
	if (base->temp)
		write(1, temp, ft_strlen(temp));
	structcheck(base, length, pflength, 2);
	write(1, r, length);
	structcheck(base, length, pflength, 3);
	free(r);
	if (base->width > pflength)
		return (base->width);
	else
		return (pflength);
}

int	ft_nbr_of_yearone(int month, int flag)
{
	if (month == 1)
		ft_putstr(" January.");
	else if (month == 2)
		ft_putstr(" February.");
	else if (month == 3)
		ft_putstr(" March.");
	else if (month == 4)
		ft_putstr(" April.");
	else if (month == 5)
		ft_putstr(" May.");
	else if (month == 6)
		ft_putstr(" June.");
	else if (month == 7)
		ft_putstr(" July.");
	else if (month == 8)
		ft_putstr(" August.");
	else if (month == 9)
		ft_putstr(" September.");
	else if (month == 10)
		ft_putstr(" October.");
	else if (month == 11)
		ft_putstr(" November.");
	else if (month == 12)
		ft_putstr(" Deсember.");
	return (3 + flag);
}

int	ft_nbr_of_yearfour(int n, int flag, int flag_d)
{
	if (!flag_d && ((n <= 334 && flag == 0) || (n <= 335 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 304 : n - 305));
		flag_d = ft_nbr_of_yearone(11, 10);
	}
	else if (!flag_d && ((n <= 365 && flag == 0) || (n <= 366 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 334 : n - 335));
		flag_d = ft_nbr_of_yearone(12, 10);
	}
	return (flag_d);
}

int	ft_nbr_of_yearthree(int n, int flag, int flag_d)
{
	if (!flag_d && ((n <= 212 && flag == 0) || (n <= 213 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 181 : n - 182));
		flag_d = ft_nbr_of_yearone(7, 6);
	}
	else if (!flag_d && ((n <= 243 && flag == 0) || (n <= 244 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 212 : n - 213));
		flag_d = ft_nbr_of_yearone(8, 8);
	}
	else if (!flag_d && ((n <= 273 && flag == 0) || (n <= 274 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 243 : n - 244));
		flag_d = ft_nbr_of_yearone(9, 11);
	}
	else if (!flag_d && ((n <= 304 && flag == 0) || (n <= 305 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 273 : n - 274));
		flag_d = ft_nbr_of_yearone(10, 9);
	}
	return (ft_nbr_of_yearfour(n, flag, flag_d));
}

int	ft_nbr_of_yeartwo(int n, int flag, int flag_d)
{
	if (!flag_d && ((n <= 90 && flag == 0) || (n <= 91 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 59 : n - 60));
		flag_d = ft_nbr_of_yearone(3, 7);
	}
	else if (!flag_d && ((n <= 120 && flag == 0) || (n <= 121 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 90 : n - 91));
		flag_d = ft_nbr_of_yearone(4, 7);
	}
	else if (!flag_d && ((n <= 151 && flag == 0) || (n <= 152 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 120 : n - 121));
		flag_d = ft_nbr_of_yearone(5, 5);
	}
	else if (!flag_d && ((n <= 181 && flag == 0) || (n <= 182 && flag == 1)))
	{
		ft_putstr(ft_itoa(flag == 0 ? n - 151 : n - 152));
		flag_d = ft_nbr_of_yearone(6, 6);
	}
	return (ft_nbr_of_yearthree(n, flag, flag_d));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelpfive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:37:19 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 19:47:17 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_timetwo(int sec)
{
	int		min;
	int		hour;

	hour = sec / 3600;
	hour < 10 ? ft_putstr("0") : 0;
	ft_putstr(ft_itoa(hour));
	min = sec % 3600;
	min / 60 < 10 ? ft_putstr(":0") : ft_putstr(":");
	ft_putstr(ft_itoa(min / 60));
	sec = min % 60;
	sec < 10 ? ft_putstr(":0") : ft_putstr(":");
	ft_putstr(ft_itoa(sec));
}

void	ft_timeone(int sec, int flag)
{
	int		min;

	if (flag == 0)
	{
		sec < 10 ? ft_putstr("00:00:0") : ft_putstr("00:00:");
		ft_putstr(ft_itoa(sec));
	}
	else if (flag == 1)
	{
		min = sec / 60;
		min < 10 ? ft_putstr("00:0") : ft_putstr("00:");
		ft_putstr(ft_itoa(min));
		sec %= 60;
		sec < 10 ? ft_putstr(":0") : ft_putstr(":");
		ft_putstr(ft_itoa(sec));
	}
	else if (flag == 2)
		ft_timetwo(sec);
}

int		ft_time(int sec)
{
	if (sec < 0)
	{
		ft_putstr("ERROR!");
		return (ft_strlen("ERROR!"));
	}
	sec = (sec > 86399 ? sec % 86400 : sec);
	if (sec < 60)
		ft_timeone(sec, 0);
	else if (sec < 3600)
		ft_timeone(sec, 1);
	else if (sec < 86400)
		ft_timeone(sec, 2);
	return (8);
}

void	writestr(char *temp, int length, int modif)
{
	int		x;
	char	y;

	x = 0;
	y = 0;
	if (modif == 6 || modif == 7)
	{
		while (x < length)
		{
			if (modif == 6)
				y = ft_toupper(temp[x]);
			if (modif == 7)
				y = ft_tolower(temp[x]);
			write(1, &y, 1);
			x++;
		}
	}
	else if (modif == 10)
		ft_rot(temp);
	else
		write(1, temp, length);
}

void	ft_rot(char *temp)
{
	int		i;
	char	c;

	i = 0;
	while (temp[i])
	{
		c = temp[i];
		if ((temp[i] >= 'A' && temp[i] <= 'Z')
				|| (temp[i] >= 'a' && temp[i] <= 'z'))
		{
			if ((temp[i] + 21 <= 'Z' && temp[i] >= 'A' && temp[i] <= 'Z')
					|| (temp[i] + 21 <= 'z'
						&& temp[i] >= 'a' && temp[i] <= 'z'))
				c = temp[i] + 21;
			else
			{
				if ((temp[i] >= 'A' && temp[i] <= 'Z'))
					c = 'A' + temp[i] + 21 - 'Z' - 1;
				else if ((temp[i] >= 'a' && temp[i] <= 'z'))
					c = 'a' + temp[i] + 21 - 'z' - 1;
			}
		}
		write(1, &c, 1);
		i++;
	}
}

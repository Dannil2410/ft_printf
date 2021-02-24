/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlehelpseven.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:59:09 by sazalee           #+#    #+#             */
/*   Updated: 2020/03/03 20:00:30 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_nbr_of_year(int nbr, int flag)
{
	int flag_d;

	flag_d = 0;
	if (nbr < 0)
	{
		ft_putstr("ERROR!");
		return (ft_strlen("ERROR!"));
	}
	nbr = (nbr > 365 && flag == 0 ? nbr % 365 : nbr);
	nbr = (nbr > 366 && flag == 1 ? nbr % 366 : nbr);
	if (nbr <= 31)
	{
		ft_putstr(ft_itoa(nbr));
		flag_d = ft_nbr_of_yearone(1, 9);
	}
	else if ((nbr <= 59 && flag == 0) || (nbr <= 60 && flag == 1))
	{
		ft_putstr(ft_itoa(nbr - 31));
		flag_d = ft_nbr_of_yearone(2, 10);
	}
	return (ft_nbr_of_yeartwo(nbr, flag, flag_d));
}

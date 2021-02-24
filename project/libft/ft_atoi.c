/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:14:39 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/03 19:15:37 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	result;
	int			i;
	int			sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		if (sign == 1 && (result > 922337203685477580
					|| (result == 922337203685477580 && str[i] + '0' >= 7)))
			return (-1);
		if (sign == -1 && (result < -922337203685477580
					|| (result == -922337203685477580 && str[i] + '0' >= '8')))
			return (0);
		result = result * 10 + str[i++] - '0';
	}
	return (sign * result);
}

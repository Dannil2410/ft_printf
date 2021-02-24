/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:13:24 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/03 18:19:50 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swape(int *mas, unsigned int temp1, unsigned int temp2)
{
	int	elet;

	elet = mas[temp1];
	mas[temp1] = mas[temp2];
	mas[temp2] = elet;
}

static void		ft_sorter(int *mas, unsigned int size)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	while (x < size)
	{
		y = 0;
		while (y < (size - 1))
		{
			if (mas[y] > mas[y + 1])
				ft_swape(mas, y, (y + 1));
			y++;
		}
		x++;
	}
}

void			ft_intsort(int *mas, unsigned int size)
{
	if (size <= 1)
		return ;
	ft_sorter(mas, size);
}

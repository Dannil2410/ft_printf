/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:11:50 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 18:20:57 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int check;

	check = 0;
	while (s[check] != '\0')
	{
		ft_putchar(s[check]);
		check++;
	}
	ft_putchar('\n');
}

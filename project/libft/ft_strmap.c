/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:12:55 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 18:10:35 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		count;

	if (!s || !f)
		return (0);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	count = 0;
	while (s[count])
	{
		result[count] = f(s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}

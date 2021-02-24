/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:45:31 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/27 16:09:13 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	count;
	char	*result;

	if (size > size + 1)
		return (NULL);
	if (!(result = ft_memalloc(size + 1)))
		return (NULL);
	count = 0;
	while (count < size)
	{
		result[count] = '\0';
		count++;
	}
	return (result);
}

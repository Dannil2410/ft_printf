/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:19:29 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/17 18:11:20 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	count;

	if (!s || !f)
		return (0);
	if (!(result = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	count = 0;
	while (s[count])
	{
		result[count] = f(count, s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}

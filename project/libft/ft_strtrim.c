/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:35:33 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/27 19:07:29 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_newl(char const *s)
{
	size_t length;

	length = ft_strlen(s);
	while (ft_spacex(*s))
	{
		length--;
		s++;
	}
	while (*s != '\0')
		s++;
	s = s - 1;
	if (length)
	{
		while (ft_spacex(*s))
		{
			length--;
			s--;
		}
	}
	return (length);
}

char			*ft_strtrim(char const *s)
{
	size_t	length;
	char	*copy;
	char	*result;

	if (s == NULL)
		return (NULL);
	length = ft_newl(s);
	copy = (char *)malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);
	result = copy;
	while (ft_spacex(*s))
		s++;
	while (length--)
		*copy++ = *s++;
	*copy = '\0';
	return (result);
}

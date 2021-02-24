/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:46:25 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/05 16:30:03 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wordfind(char *word, char c)
{
	char *temp;

	temp = word;
	while (*word && (*word != c))
		word++;
	*word = '\0';
	return (ft_strdup(temp));
}

static void	ft_freewords(char **words, size_t count)
{
	while (count--)
		ft_strdel(&(words[count]));
	free(*words);
}

static char	**ft_findall(char *s, char c, size_t counterword)
{
	char	**words;
	char	*word;
	size_t	count;

	count = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (counterword + 1))))
	{
		while (count < counterword)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_wordfind(s, c)))
				{
					ft_freewords(words, count);
					return (NULL);
				}
				words[count++] = word;
				s = s + (ft_strlen(word) + 1);
			}
		}
		words[count] = NULL;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char **words;
	char *single;

	if ((!s) || (!(single = ft_strdup((char *)s))))
		return (NULL);
	words = ft_findall(single, c, ft_wordsc(single, c));
	free(single);
	return (words);
}

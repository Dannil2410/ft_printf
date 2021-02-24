/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:39:55 by sazalee           #+#    #+#             */
/*   Updated: 2019/05/05 16:32:19 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cleaner(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *temp;
	t_list *tempb;

	tempb = NULL;
	result = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		if (!(temp = f(lst)))
		{
			if (result)
				ft_lstdel(&result, &ft_cleaner);
			return (NULL);
		}
		if (tempb)
			tempb->next = temp;
		else
			result = temp;
		lst = lst->next;
		tempb = temp;
	}
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazalee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:20:34 by sazalee           #+#    #+#             */
/*   Updated: 2019/04/27 16:38:05 by sazalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cycle;
	t_list *temp;

	cycle = *alst;
	while (cycle && del)
	{
		temp = cycle;
		ft_lstdelone(&cycle, del);
		cycle = temp->next;
	}
	*alst = NULL;
}

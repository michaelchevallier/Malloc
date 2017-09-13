/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:08:16 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/11 18:08:18 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	dbldelone_else(t_elem *to_remove)
{
	to_remove->next->prev = to_remove->prev;
	to_remove->prev->next = to_remove->next;
}

void			ft_lstdbldelone(t_dbllist **list, t_elem *to_remove)
{
	if (to_remove == NULL)
		return ;
	if ((*list)->length == 1)
	{
		ft_lstdbldel(list);
		*list = ft_lstdblnew();
		(*list)->length = 0;
		return ;
	}
	else if (to_remove->next == NULL)
	{
		(*list)->tail = to_remove->prev;
		(*list)->tail->next = NULL;
	}
	else if (to_remove->prev == NULL)
	{
		(*list)->head = to_remove->next;
		(*list)->head->prev = NULL;
	}
	else
		dbldelone_else(to_remove);
	free(to_remove->content);
	free(to_remove);
	(*list)->length--;
}

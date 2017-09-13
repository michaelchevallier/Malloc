/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbldel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:06:14 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/20 16:12:56 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdbldel(t_dbllist **list)
{
	t_elem	*tmp;
	t_elem	*tmp_next;

	tmp = (*list)->head;
	while (tmp != NULL)
	{
		free(tmp->content);
		tmp->content = NULL;
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	(*list)->tail = NULL;
	(*list)->head = NULL;
	free(*list);
	*list = NULL;
}

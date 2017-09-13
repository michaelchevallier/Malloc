/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:45:18 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/20 16:13:12 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_dbllist	*ft_lstdblnew(void)
{
	t_dbllist	*list;

	list = (t_dbllist *)malloc(sizeof(t_dbllist));
	if (list == NULL)
		return (NULL);
	else
	{
		list->length = 0;
		list->tail = NULL;
		list->head = NULL;
	}
	return (list);
}

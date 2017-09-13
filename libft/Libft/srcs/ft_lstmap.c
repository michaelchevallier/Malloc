/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:02:11 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/03 17:12:36 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL || lst == NULL)
		return (NULL);
	new_list = (*f)(lst);
	new_list->next = ft_lstmap(lst->next, f);
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlsthead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:27:51 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/08 12:01:43 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putlsthead(t_dbllist *list)
{
	t_elem	*tmp;

	tmp = list->head;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->next;
	}
}

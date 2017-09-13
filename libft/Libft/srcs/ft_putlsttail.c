/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlsttail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:29:24 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/10 15:30:59 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putlsttail(t_dbllist *list)
{
	t_elem	*tmp;

	tmp = list->tail;
	while (tmp != NULL)
	{
		ft_putstr(tmp->content);
		tmp = tmp->prev;
	}
}

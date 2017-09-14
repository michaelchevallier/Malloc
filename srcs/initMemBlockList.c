/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMemBlockList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:40:11 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:40:18 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"



void		initMemBlockList(t_memblocklist *list, t_blocktype type)
{
	list->size = 0;
	list->type = type;
	list->next = NULL;
	if (type == TINY)
		setTiny(list);
	// else if (type == SMALL)
	// 	setSmall(list);
	// else if (type == LARGE)
	// 	setLarge(list);
	else
		return ;

}
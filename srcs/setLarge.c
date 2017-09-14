/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setLarge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:59:14 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:59:21 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		setLarge(t_memblocklist *list)
{
	int			i;

	i = 0;
	list->current = (t_memblock *)mmap(0, sizeof(t_memblock),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->size += 1;
	list->current->size = 0;
	list->current->starting_address = NULL;
	list->current->type = LARGE;
}

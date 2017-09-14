/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setSmall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:58:59 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:59:06 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		setSmall(t_memblocklist *list)
{
	int			i;

	i = 0;
	list->current = (t_memblock *)mmap(0, sizeof(t_memblock),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->size += 1;
	list->current->size = SMALLSIZE * PAGESIZE;
	list->current->starting_address = (void *)mmap(0, SMALLSIZE * PAGESIZE,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->current->type = SMALL;
	while (i < BLOCKDIV)
	{
		list->current->alloted_mem[i] = 0;
		i++;
	}
}
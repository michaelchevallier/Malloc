/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setTiny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:58:38 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:58:46 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		setTiny(t_memblocklist *list)
{
	int			i;

	i = 0;
	list->current = (t_memblock *)mmap(0, sizeof(t_memblock),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->size += 1;
	list->current->size = TINYSIZE * PAGESIZE;
	list->current->starting_address = (void *)mmap(0, TINYSIZE * PAGESIZE,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->current->type = TINY;
	while (i < BLOCKDIV)
	{
		list->current->alloted_mem[i] = 0;
		i++;
	}
}

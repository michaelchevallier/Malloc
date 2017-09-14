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

t_block		initblock(t_block *block, int i, t_memblock *memblock)
{
	block = (t_block *)mmap(0, sizeof(t_block), PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0);
	block->size = memblock->size / 100;
	block->id = i;
	block->isused = 0;
	block->parent_address = memblock->starting_address;
	block->starting_address = memblock->starting_address +
		(i * block->size);
	printf("%p\n", block->starting_address);
	block->alloted_mem = 0;
	return (*block);
}

void		setTiny(t_memblocklist *list)
{
	int			i;

	i = 0;
	list->current = (t_memblock *)mmap(0, sizeof(t_memblock),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->size += 1;
	list->current->size = TINYSIZE * PAGESIZE;
	list->current->alloted_mem = 0;
	list->current->starting_address = (void *)mmap(0, TINY * PAGESIZE,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	list->current->type = TINY;
	list->current->isfull = 0;
	while (i <= BLOCKDIV)
	{
		list->current->blocks[i] = initblock(list->current->blocks, i, list->current);
		i++;
	}
}

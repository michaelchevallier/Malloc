/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:21:58 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/18 11:22:06 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int				largeSpecialCase(t_memblocklist *list, size_t size)
{
	if (set_large(list, size) == -1)
		return (-1);
	list->alloted_mem[0] = size;
	return (0);
}

void			*assign_block(t_memblocklist *list, size_t size)
{
		int		i;
		t_memblocklist *tmplist;

		i = 0;
		tmplist = list;
	// printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ DEBUG assign_block: %lu { %p }\n", tmplist->alloted_mem[i], tmplist->start_add);
		while (tmplist->alloted_mem[i] != 0)
		{
	// printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ DEBUG assign_block: %lu { %p }\n", tmplist->alloted_mem[i], tmplist->start_add);
			i++;
			if (i == BLOCKDIV || list->type == LARGE)
			{
				if (tmplist->next == NULL)
					if (create_new_memblock(list, tmplist->type) == -1)
						return (NULL);
					tmplist = tmplist->next;
				i = 0;
			}
		}
		tmplist->alloted_mem[i] = size;
		if (tmplist->type == TINY)
		{
		// printf("\nassign_block\n[TYPE : {%d}]\n[start_add : {%p}]\n[ALLOTED_MEM [%d] : {%lu}]\n", list->type, tmplist->start_add, i, tmplist->alloted_mem[i]);
			return (tmplist->start_add + (i * TBLOCK));
		}
		else if (tmplist->type == SMALL)
		{
		// printf("\nassign_block\n[TYPE : {%d}]\n[start_add : {%p}]\n[ALLOTED_MEM [%d] : {%lu}]\n", list->type, tmplist->start_add, i, tmplist->alloted_mem[i]);
			return (tmplist->start_add + (i * SBLOCK));
		}
		if (largeSpecialCase(tmplist, size) == -1)
			return (NULL);
		// printf("\nassign_block\n[TYPE : {%d}]\n[start_add : {%p}]\n[ALLOTED_MEM [%d] : {%lu}]\n",list->type, tmplist->start_add, i, tmplist->alloted_mem[i]);
		return (tmplist->start_add);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignBlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:21:58 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/18 11:22:06 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int				largeSpecialCase(t_memblocklist *original_list, t_memblocklist *list, size_t size)
{
	if (setLarge(list, size) == -1)
		return (-1);
	list->alloted_mem[0] = size;
	if (createNewMemBlock(original_list, list->type, size) == -1)
		return (-1);
	return (0);
}

void			*assignBlock(t_memblocklist *list, size_t size)
{
		int		i;
		t_memblocklist *tmplist;

		i = 0;
		tmplist = list;
		while (tmplist->alloted_mem[i] != 0)
		{
			i++;
			if (i == BLOCKDIV || size > SMALLBLOCK)
			{
				if ((tmplist = tmplist->next) == NULL)
					return (NULL);
				i = 0;
			}
		}
		tmplist->alloted_mem[i] = size;
		if (i == 99 && createNewMemBlock(list, tmplist->type, size) == -1)
			return (NULL);
		if (tmplist->type == TINY)
		{
		// printf("\n\nassignBlock\n[TYPE : {%d}]\n[STARTING_ADDRESS : {%p}]\n[ALLOTED_MEM [%d] : {%lu}]", list->type, tmplist->starting_address, i, tmplist->alloted_mem[i]);
			return (tmplist->starting_address + (i * TINYBLOCK));
		}
		else if (tmplist->type == SMALL)
		{
		// printf("\n\nassignBlock\n[TYPE : {%d}]\n[STARTING_ADDRESS : {%p}]\n[ALLOTED_MEM [%d] : {%lu}]", list->type, tmplist->starting_address, i, tmplist->alloted_mem[i]);
			return (tmplist->starting_address + (i * SMALLBLOCK));
		}
		if (largeSpecialCase(list, tmplist, size) == -1)
			return (NULL);
		// printf("\n\nassignBlock\n[TYPE : {%d}]\n[STARTING_ADDRESS : {%p}]\n[ALLOTED_MEM [%d] : {%lu}]",list->type, tmplist->starting_address, i, tmplist->alloted_mem[i]);
		return (tmplist->starting_address);
}

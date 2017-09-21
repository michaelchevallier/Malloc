/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_memblock.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:00:29 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/18 14:00:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		create_new_memblock(t_memblocklist *list, t_blocktype type)
{
	t_memblocklist		*new_block;
	t_memblocklist		*tmplist;

	tmplist = list;
	new_block = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (new_block == MAP_FAILED)
		return (-1);
	if (type == TINY && set_tiny(new_block) == -1)
		return (-1);
	if (type == SMALL && set_small(new_block) == -1)
		return (-1);
	if (type == LARGE)
		set_large(new_block, 0);
	while (tmplist->next != NULL)
		tmplist = tmplist->next;
	tmplist->next = new_block;
	return (0);
}

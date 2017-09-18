/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createNewMemBlock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:00:29 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/18 14:00:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		createNewMemBlock(t_memblocklist *list, t_blocktype type, size_t size)
{
	t_memblocklist		*newBlock;
	t_memblocklist		*tmplist;

	tmplist = list;
	newBlock = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	if (newBlock == MAP_FAILED)
		return (-1);
	if (type == TINY && setTiny(newBlock) == -1)
		return (-1);
	if (type == SMALL && setSmall(newBlock) == -1)
		return(-1);
	if (type == LARGE && setLarge(newBlock, size) == -1)
		return (-1);
	while (tmplist->next != NULL)
		tmplist = tmplist->next;
	tmplist->next = newBlock;
	return (0);
}
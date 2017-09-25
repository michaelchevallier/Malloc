/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:31:20 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/13 16:31:43 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static t_memblocklist	*remove_from_list(t_memblocklist *list,
	t_memblocklist *o_list)
{
	t_memblocklist *tmplist;
	t_memblocklist *tmplist2;

	tmplist = o_list;
	tmplist2 = NULL;
	while (tmplist != NULL)
	{
		if (is_same_ptr((void *)tmplist, (void *)list))
		{
			if (tmplist2 == NULL)
				o_list = tmplist->next;
			else
				tmplist2->next = tmplist->next;
			munmap(tmplist, sizeof(t_memblocklist));
			return (o_list);
		}
		tmplist2 = tmplist;
		tmplist = tmplist->next;
	}
	return (o_list);
}

static void				free_and_destroy(t_memblocklist *list)
{
	if (list)
	{
		if (list->type == TINY)
		{
			munmap(list->start_add, TINYSIZE);
			g_fmem->tinylist = remove_from_list(list, g_fmem->tinylist);
		}
		else if (list->type == SMALL)
		{
			munmap(list->start_add, SMALLSIZE);
			g_fmem->smalllist = remove_from_list(list, g_fmem->smalllist);
		}
		else if (list->type == LARGE)
		{
			munmap(list->start_add, list->alloted_mem[0]);
			if (list->next != NULL)
				g_fmem->largelist = remove_from_list(list, g_fmem->largelist);
		}
	}
}

static void				*freeptr(t_memblocklist *list, int i)
{
	int				j;

	j = -1;
	if (list->type != LARGE)
		list->alloted_mem[i] = 0;
	while (++j < BLOCKDIV)
	{
		if (list->alloted_mem[j] != 0 && list->type != LARGE)
			return (NULL);
	}
	if ((is_same_ptr((void *)list, (void *)g_fmem->tinylist) ||
		is_same_ptr((void *)list, (void *)g_fmem->smalllist)))
		return (NULL);
	else
		list->alloted_mem[i] = 0;
	free_and_destroy(list);
	return (NULL);
}

static void				*find_addr_inlist(void *ptr, t_memblocklist *list)
{
	t_memblocklist	*tmplist;
	int				i;

	i = 0;
	tmplist = list;
	while (tmplist != NULL)
	{
		while (i < BLOCKDIV && tmplist->type != LARGE)
		{
			if (tmplist->type == TINY &&
				is_same_ptr(ptr, (void *)tmplist->TBLOCKADDR))
				return (freeptr(tmplist, i));
			else if ((tmplist->type) == SMALL &&
				is_same_ptr(ptr, (void *)tmplist->SBLOCKADDR))
				return (freeptr(tmplist, i));
			i++;
		}
		if (is_same_ptr(ptr, (void *)tmplist->start_add))
			return (freeptr(tmplist, 0));
		tmplist = tmplist->next;
	}
	return ((void *)-1);
}

void					free(void *ptr)
{
	if (ptr == NULL)
		return ;
	if (find_addr_inlist(ptr, g_fmem->largelist) == (void *)-1)
		if (find_addr_inlist(ptr, g_fmem->smalllist) == (void *)-1)
			find_addr_inlist(ptr, g_fmem->tinylist);
}

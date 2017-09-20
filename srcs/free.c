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

static void	removeFromList(t_memblocklist *list, t_memblocklist *o_list)
{
	printf("************** REMOVEFROMLIST *********************** \n");

	t_memblocklist *tmplist;
	t_memblocklist *tmplist2;

	tmplist = o_list->next;
	tmplist2 = o_list;

	while (tmplist != NULL)
	{
		printf("\n yolo : [ %p ] , [ %p ]        {[ %p ],  [ %p ]}\n", tmplist, list, g_fmem->smalllist, g_fmem->tinylist);

		if (isSamePtr((void *)tmplist, (void *)list))
		{
	printf("#######################################################################DEBUG [ %p ]\n", list);
			munmap(list, sizeof(t_memblocklist));
			tmplist2->next = tmplist->next;
			return ;
		}
		tmplist = tmplist->next;
		tmplist2 = tmplist2->next;
	}
}

static void		freeAndDestroy(t_memblocklist *list)
{
	printf("************** FREEANDDESTROY *********************** \n");

	if (list->type == TINY)
	{
		munmap(list->start_add, TINYSIZE);
		removeFromList(list, g_fmem->tinylist);
	}
	if (list->type == SMALL)
	{
		munmap(list->start_add, SMALLSIZE);
		removeFromList(list, g_fmem->smalllist);
	}
	if (list->type == LARGE)
	{
		munmap(list->start_add, list->alloted_mem[0]);
		// if (isSamePtr((void *)list, (void *)(g_fmem->largelist)))
			// return ;
		removeFromList(list, g_fmem->largelist);
	}
}

static void		*freeptr(t_memblocklist *list, int i)
{
	printf("************** FREEPTR *********************** \n");
	int				j;

	j = -1;
	if (list->type != LARGE)
		list->alloted_mem[i] = 0;
	while (++j < BLOCKDIV)
	{
		if (list->alloted_mem[j] != 0 && list->type != LARGE)
			return (NULL);
	}
	if ((isSamePtr((void *)list, (void *)g_fmem->tinylist) ||
		isSamePtr((void *)list, (void *)g_fmem->smalllist)))
		return (NULL);
	else
	// (isSamePtr((void *)list, (void *)(g_fmem->largelist)))
		list->alloted_mem[i] = 0;
	freeAndDestroy(list);
	return (NULL);
}

static void		*findAddrInList(void *ptr, t_memblocklist *list)
{
	printf("************** FINDADDRINLIST *********************** \n");
	t_memblocklist	*tmplist;
	int				i;

	i = 0;
	tmplist = list;
	while (tmplist != NULL)
	{
		while (i < BLOCKDIV && tmplist->type != LARGE)
		{
			if (tmplist->type == TINY)
			{
				if (isSamePtr(ptr, (void *)tmplist->TBLOCKADDR))
					return (freeptr(tmplist, i));
			}
			else if ((tmplist->type) == SMALL)
			{
				if (isSamePtr(ptr, (void *)tmplist->SBLOCKADDR))
					return (freeptr(tmplist, i));
			}
			i++;
		}
		if (isSamePtr(ptr, (void *)tmplist->start_add))
			return (freeptr(tmplist, 0));
		tmplist = tmplist->next;
	}
printf("############################################### DEBuG pas trouver free\n");
	return ((void *)-1);
}

void		free(void *ptr)
{
	printf("**************************FREE***********************\n");
	if (ptr == NULL)
	{
		printf(" ***************** RECEIVED POINTER IS NULL ****************** \n");
		return ;
	}

	if (findAddrInList(ptr, g_fmem->largelist) == (void *) -1)
		if (findAddrInList(ptr, g_fmem->smalllist) == (void *)-1)
			findAddrInList(ptr, g_fmem->tinylist);
}

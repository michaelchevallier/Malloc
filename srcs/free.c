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

static t_memblocklist	*removeFromList(t_memblocklist *list, t_memblocklist *o_list)
{
	// printf("************** REMOVEFROMLIST *********************** \n");

	t_memblocklist *tmplist;
	t_memblocklist *tmplist2;

	tmplist = o_list;
	tmplist2 = NULL;

	while (tmplist != NULL)
	{
		// printf("\n yolo : [%p ] [ %p ] , [ %p ]        {[ %p ],  [ %p ]}\n", tmplist, tmplist2, list, g_fmem->smalllist, g_fmem->tinylist);

		if (isSamePtr((void *)tmplist, (void *)list))
		{
	// printf("#######################################################################DEBUG [ %p ]\n", list);
	// printf("hi1\n");
			if (tmplist2 == NULL)
			{
				// printf("hi2\n");
				// printf("YOO : [%p]  [%p] \n", o_list, tmplist->next);
				o_list = tmplist->next;
				// printf("YOO2 : [%p]  [%p] \n", o_list, g_fmem->largelist);
			}
			else
			{
				// printf("hi3\n");
				tmplist2->next = tmplist->next;
			}
			munmap(tmplist, sizeof(t_memblocklist));
	// printf("hi4\n");
			return (o_list);
		}
		tmplist2 = tmplist;
		tmplist = tmplist->next;
	}
	return(o_list);
}

static void		freeAndDestroy(t_memblocklist *list)
{
	// printf("************** FREEANDDESTROY *********************** \n");

	if (list->type == TINY)
	{
		munmap(list->start_add, TINYSIZE);
		g_fmem->tinylist = removeFromList(list, g_fmem->tinylist);
	}
	if (list->type == SMALL)
	{
		munmap(list->start_add, SMALLSIZE);
		g_fmem->smalllist = removeFromList(list, g_fmem->smalllist);
	}
	if (list->type == LARGE)
	{
		munmap(list->start_add, list->alloted_mem[0]);
		if (list->next != NULL)
			g_fmem->largelist = removeFromList(list, g_fmem->largelist);
	}
	// show_alloc_mem();

}

static void		*freeptr(t_memblocklist *list, int i)
{
	// printf("************** FREEPTR *********************** \n");
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
	// printf("************** FINDADDRINLIST *********************** \n");
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
// printf("############################################### DEBuG pas trouver free\n");
	return ((void *)-1);
}

void		free(void *ptr)
{
	// printf("**************************FREE***********************\n");
	if (ptr == NULL)
	{
		printf(" ***************** RECEIVED POINTER IS NULL ****************** \n");
		return ;
	}

	if (findAddrInList(ptr, g_fmem->largelist) == (void *) -1)
		if (findAddrInList(ptr, g_fmem->smalllist) == (void *)-1)
			findAddrInList(ptr, g_fmem->tinylist);

	// show_alloc_mem();
}

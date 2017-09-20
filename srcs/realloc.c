/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:31:49 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/13 16:32:00 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		*smallrealloc(t_memblocklist *list, int i, size_t size,
	size_t cpysize)
{
	void			*ptr;

	if (size <= SBLOCK)
	{
		ptr = list->SBLOCKADDR;
		list->alloted_mem[i] = size;
	}
	else
	{
		ptr = malloc(size);
		if (ptr == NULL)
			return (NULL);
		ft_memcpy(ptr, (const void *)list->SBLOCKADDR, cpysize);
		free(list->SBLOCKADDR);
	}
	return (ptr);
}

static void		*tinyrealloc(t_memblocklist *list, int i, size_t size,
	size_t cpysize)
{
	void			*ptr;

	if (size <= TBLOCK)
	{
		ptr = list->TBLOCKADDR;
		list->alloted_mem[i] = size;
	}
	else
	{
		ptr = malloc(size);
		if (ptr == NULL)
			return (NULL);
		ft_memcpy(ptr, (const void *)list->TBLOCKADDR, cpysize);
		free(list->TBLOCKADDR);
	}
	return (ptr);

}

static void		*tryrealloc(t_memblocklist *list, int i, size_t size)
{
	void			*ptr;
	size_t			cpysize;

	if (size == list->alloted_mem[i])
		return (list->start_add);
	else if (size < list->alloted_mem[i])
		cpysize = size;
	else if (size > list->alloted_mem[i])
		cpysize = list->alloted_mem[i];
	if (list->type == TINY &&
		(ptr = tinyrealloc(list, i, size, cpysize)) == NULL)
		return (NULL);
	else if (list->type == SMALL &&
		(ptr = smallrealloc(list, i, size, cpysize)) == NULL)
		return (NULL);
	else if (list->type == LARGE)
	{
		if ((ptr = malloc(size)) == NULL)
			return (NULL);
	// show_alloc_mem();
		ft_memcpy(ptr, (const void *)list->start_add, cpysize);
	printf("############################################# DEBUG : [ %p ] [ %p ]\n", ptr, list->start_add);
		free(list->start_add);
	}
	return (ptr);
}

static void		*findAddrInList(void *ptr, t_memblocklist *list, size_t size)
{
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
					return (tryrealloc(tmplist, i, size));
			}
			else if ((tmplist->type) == SMALL)
			{
				if (isSamePtr(ptr, (void *)tmplist->SBLOCKADDR))
					return (tryrealloc(tmplist, i, size));
			}
			i++;
		}
		if (isSamePtr(ptr, (void *)tmplist->start_add))
			return (tryrealloc(tmplist, 0, size));
		tmplist = tmplist->next;
	}
	printf("############################################### DEBUG pas trouver\n");
	return ((void *)-1);
}

void						*realloc(void *ptr, size_t size)
{
	void		*returnedpointer;


	if (ptr == NULL)
		return (NULL);
	returnedpointer = findAddrInList(ptr, g_fmem->largelist, size);
	returnedpointer = findAddrInList(ptr, g_fmem->smalllist, size);
	returnedpointer = findAddrInList(ptr, g_fmem->tinylist, size);
	if (returnedpointer == (void *)-1)
		return (NULL);
	return (returnedpointer);
}

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
		ft_memcpy(ptr, (const void *)list->start_add, cpysize);
		free(list->start_add);
	}
	return (ptr);
}

static void		*find_addr_list(void *ptr, t_memblocklist *list, size_t size)
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
				return (tryrealloc(tmplist, i, size));
			else if ((tmplist->type) == SMALL &&
				is_same_ptr(ptr, (void *)tmplist->SBLOCKADDR))
				return (tryrealloc(tmplist, i, size));
			i++;
		}
		if (is_same_ptr(ptr, (void *)tmplist->start_add))
			return (tryrealloc(tmplist, 0, size));
		tmplist = tmplist->next;
	}
	return ((void *)-1);
}

void			*realloc(void *ptr, size_t size)
{
	void		*rptr;

	rptr = (void *)-1;
	if (ptr == NULL)
		return (malloc(size));
	if ((rptr = find_addr_list(ptr, g_fmem->largelist, size)) == (void *)-1)
		if ((rptr = find_addr_list(ptr, g_fmem->smalllist, size)) == (void *)-1)
			rptr = find_addr_list(ptr, g_fmem->tinylist, size);
	if (rptr == (void *)-1)
		return (NULL);
	return (rptr);
}

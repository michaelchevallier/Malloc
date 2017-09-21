/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 13:14:31 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/18 13:14:51 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static size_t				printmeminfo(t_memblocklist *list)
{
	int					i;
	size_t				totalmem;

	i = 0;
	totalmem = 0;
// ft_putstr("\nprintmeminfo\n");
	if (list->type == TINY)
		ft_putstr("TINY : 0x");
	else if (list->type == SMALL)
		ft_putstr("SMALL : 0x");
	else
		ft_putstr("LARGE : 0x");
	// printf("%p\n",list->start_add);
	putoabase((uintmax_t)list->start_add, 16);
	ft_putchar('\n');
	while (i < BLOCKDIV)
	{
		if (list->alloted_mem[i] > 0)
		{
			totalmem += list->alloted_mem[i];
	// printf("%p\n", list->start_add);
			ft_putstr("0x");
			if (list->type == TINY)
				putoabase((uintmax_t)list->start_add + (i * TBLOCK), 16);
			else if (list->type == SMALL)
				putoabase((uintmax_t)list->start_add + (i * SBLOCK), 16);
			else
				putoabase((uintmax_t)list->start_add, 16);
			ft_putstr(" - 0x");
	// printf("%p\n", list->start_add);
			if (list->type == TINY)
				putoabase((uintmax_t)list->start_add + (i * TBLOCK) + list->alloted_mem[i], 16);
			else if (list->type == SMALL)
				putoabase((uintmax_t)list->start_add + (i * SBLOCK) + list->alloted_mem[i], 16);
			else
				putoabase((uintmax_t)list->start_add + list->alloted_mem[i], 16);
			ft_putstr(" : ");
			ft_sputnbr(list->alloted_mem[i]);
			ft_putendl(" octets");
		}
		i++;
	}
	return (totalmem);
// ft_putstr("\nprintmeminfo -> return\n");
}

static t_memblocklist	*compareAddresses(t_memblocklist *list1,
	t_memblocklist *list2, t_memblocklist *list3)
{
	void	*list1addr;
	void	*list2addr;
	void	*list3addr;

// ft_putstr("\ncompareAddress\n");
// printf("%p, %p, %p\n", list1, list2, list3);
	if (list1 == NULL && list2 == NULL && list3 == NULL)
		return (NULL);
	if (list1 == NULL)
		list1addr = (void *)-1;
	else
		list1addr = list1->start_add;
	if (list2 == NULL)
		list2addr = (void *)-1;
	else
		list2addr = list2->start_add;
	if (list3 == NULL)
		list3addr = (void *)-1;
	else
		list3addr = list3->start_add;
// ft_putstr("\ncompareAddress -> return\n");
	if (list1addr < list2addr && list1addr < list3addr)
		return (list1);
	if (list2addr < list1addr && list2addr < list3addr)
		return (list2);
	if (list3addr < list1addr && list3addr < list2addr)
		return (list3);
	return (NULL);
}

static void				*findPossibleAddress(t_memblocklist *list, void *addr)
{
	t_memblocklist		*tmplist;
	t_memblocklist		*returnedlist;
	void				*currentsmall;

// ft_putstr("\nfindPossibleAddress\n");
// printf("findPossibleAddress : [%p]\n", list);
	tmplist = list;
	currentsmall = (void *)-1;
	returnedlist = NULL;
	while (tmplist)
	{
		if (tmplist->start_add > addr && tmplist->start_add < currentsmall)
		{
			currentsmall = tmplist->start_add;
			returnedlist = tmplist;
		}
		tmplist = tmplist->next;
	}
// ft_putstr("\nfindPossibleAddress -> return\n");
	return (returnedlist);
}

void					show_alloc_mem()
{
	int					i;
	void				*prevaddr;
	t_memblocklist		*list;
	size_t				totalmem;

	i = 0;
	totalmem = 0;
	prevaddr = (void *)0;
	if (g_fmem != NULL)
	{
		while (i == 0)
		{
			if ((list = compareAddresses(
				findPossibleAddress(g_fmem->tinylist, prevaddr),
				findPossibleAddress(g_fmem->smalllist, prevaddr),
				findPossibleAddress(g_fmem->largelist, prevaddr))) == NULL)
				i = 1;
			else
			{
				totalmem += printmeminfo(list);
				prevaddr = list->start_add;
			}
		}
		ft_putstr("Total : ");
		ft_sputnbr(totalmem);
		ft_putendl(" octets");
	}

}
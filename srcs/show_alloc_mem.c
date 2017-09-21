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

static t_memblocklist	*compare_addr(t_memblocklist *list1,
	t_memblocklist *list2, t_memblocklist *list3)
{
	void	*list1addr;
	void	*list2addr;
	void	*list3addr;

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
	if (list1addr < list2addr && list1addr < list3addr)
		return (list1);
	if (list2addr < list1addr && list2addr < list3addr)
		return (list2);
	if (list3addr < list1addr && list3addr < list2addr)
		return (list3);
	return (NULL);
}

static void				*find_possible_addr(t_memblocklist *list, void *addr)
{
	t_memblocklist		*tmplist;
	t_memblocklist		*returnedlist;
	void				*currentsmall;

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
	return (returnedlist);
}

static void				final_print(size_t totalmem)
{
	ft_putstr("Total : ");
	ft_sputnbr(totalmem);
	ft_putendl(" octets");
}

void					show_alloc_mem(void)
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
			if ((list = compare_addr(
				find_possible_addr(g_fmem->tinylist, prevaddr),
				find_possible_addr(g_fmem->smalllist, prevaddr),
				find_possible_addr(g_fmem->largelist, prevaddr))) == NULL)
				i = 1;
			else
			{
				totalmem += printmeminfo(list);
				prevaddr = list->start_add;
			}
		}
		final_print(totalmem);
	}
}

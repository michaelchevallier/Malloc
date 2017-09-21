/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:45:29 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/21 13:45:41 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void		second_part(t_memblocklist *list, int i)
{
	if (list->type == TINY)
		putoabase((uintmax_t)list->start_add + (i * TBLOCK) +
			list->alloted_mem[i], 16);
	else if (list->type == SMALL)
		putoabase((uintmax_t)list->start_add + (i * SBLOCK) +
			list->alloted_mem[i], 16);
	else
		putoabase((uintmax_t)list->start_add + list->alloted_mem[i], 16);
	ft_putstr(" : ");
	ft_sputnbr(list->alloted_mem[i]);
	ft_putendl(" octets");
}

static void		first_part(t_memblocklist *list, int i)
{
	ft_putstr("0x");
	if (list->type == TINY)
		putoabase((uintmax_t)list->start_add + (i * TBLOCK), 16);
	else if (list->type == SMALL)
		putoabase((uintmax_t)list->start_add + (i * SBLOCK), 16);
	else
		putoabase((uintmax_t)list->start_add, 16);
	ft_putstr(" - 0x");
}

static void		prequel(t_memblocklist *list)
{
	if (list->type == TINY)
		ft_putstr("TINY : 0x");
	else if (list->type == SMALL)
		ft_putstr("SMALL : 0x");
	else
		ft_putstr("LARGE : 0x");
	putoabase((uintmax_t)list->start_add, 16);
	ft_putchar('\n');
}

size_t			printmeminfo(t_memblocklist *list)
{
	int			i;
	size_t		totalmem;

	i = 0;
	totalmem = 0;
	prequel(list);
	while (i < BLOCKDIV)
	{
		if (list->alloted_mem[i] > 0)
		{
			totalmem += list->alloted_mem[i];
			first_part(list, i);
			second_part(list, i);
		}
		i++;
	}
	return (totalmem);
}

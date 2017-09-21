/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_large.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:59:14 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:59:21 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		set_large(t_memblocklist *list, size_t size)
{
	int		i;

	i = 0;
	if (size != 0)
		list->start_add = (void *)mmap(0, size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (list->start_add == MAP_FAILED)
		return (-1);
	list->type = LARGE;
	list->next = NULL;
	while (i < BLOCKDIV)
	{
		list->alloted_mem[i] = 0;
		i++;
	}
	return (0);
}

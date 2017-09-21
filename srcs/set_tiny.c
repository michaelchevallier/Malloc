/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tiny.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:58:38 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:58:46 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			set_tiny(t_memblocklist *list)
{
	int			i;

	i = 0;
	list->start_add = (void *)mmap(0, TINYSIZE,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (list->start_add == MAP_FAILED)
		return (-1);
	list->type = TINY;
	list->next = NULL;
	while (i < BLOCKDIV)
	{
		list->alloted_mem[i] = 0;
		i++;
	}
	return (0);
}

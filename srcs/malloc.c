/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:53:54 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/13 14:49:34 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_fmemblocks	*g_fmem = NULL;

void			*malloc(size_t size)
{
	void		*malloc;
	if (g_fmem == NULL)
		if ((g_fmem = mapFirstMemBlocks()) == NULL)
			return (NULL);
	// printf("\nsize: %lu\n", size);
	if (size <= TBLOCK)
		malloc = assignBlock(g_fmem->tinylist, size);
	else if (size <= SBLOCK)
		malloc = assignBlock(g_fmem->smalllist, size);
	else
		malloc = assignBlock(g_fmem->largelist, size);
	// printf("address : [%p] [%p] [%p] [%p]\n ", g_fmem, g_fmem->tinylist, g_fmem->smalllist, g_fmem->largelist);
	// printf("sizeof : [%lu], [%d] [%d] [%d]\n",
	// 	sizeof(g_fmem), g_fmem->tinylist->type, g_fmem->smalllist->type, g_fmem->largelist->type);
	return (malloc);
}
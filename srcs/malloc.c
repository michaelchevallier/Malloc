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
		if ((g_fmem = map_first_memblocks()) == NULL)
			return (NULL);
	if (size <= TBLOCK)
		malloc = assign_block(g_fmem->tinylist, size);
	else if (size <= SBLOCK)
		malloc = assign_block(g_fmem->smalllist, size);
	else
		malloc = assign_block(g_fmem->largelist, size);
	return (malloc);
}

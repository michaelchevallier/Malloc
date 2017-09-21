/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_first_memblocks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:30:51 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 11:31:03 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_fmemblocks		*map_first_memblocks(void)
{
	t_fmemblocks		*fmemblocks;

	fmemblocks = (t_fmemblocks *)mmap(0, sizeof(t_fmemblocks),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	fmemblocks->tinylist = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	fmemblocks->smalllist = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	fmemblocks->largelist = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((init_memblock_list(fmemblocks->tinylist, TINY)) == -1 ||
		(init_memblock_list(fmemblocks->smalllist, SMALL)) == -1 ||
		(init_memblock_list(fmemblocks->largelist, LARGE)) == -1)
		return (NULL);
	return (fmemblocks);
}

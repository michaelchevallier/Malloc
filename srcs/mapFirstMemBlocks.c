/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfirstMemBlocks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:30:51 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 11:31:03 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_fmemblocks		*mapFirstMemBlocks()
{
	t_fmemblocks		*fmemblocks;

	fmemblocks = (t_fmemblocks *)mmap(0, sizeof(t_fmemblocks),
		PROT_READ | PROT_WRITE, MAP_ANON, MAP_PRIVATE);
	fmemblocks->tinylist = (t_tinylist *)mmap(0, sizeof(t_tinylist),
		PROT_READ | PROT_WRITE, MAP_ANON, MAP_PRIVATE);
	fmemblocks->smalllist = (t_smalllist *)mmap(0, sizeof(t_smalllist),
		PROT_READ | PROT_WRITE, MAP_ANON, MAP_PRIVATE);
	fmemblocks->largelist = (t_largelist *)mmap(0, sizeof(t_largelist),
		PROT_READ | PROT_WRITE, MAP_ANON, MAP_PRIVATE);
	initTinyMem
	return (fmemblocks);
}
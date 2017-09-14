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
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	fmemblocks->tinylist = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	fmemblocks->smalllist = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	fmemblocks->largelist = (t_memblocklist *)mmap(0, sizeof(t_memblocklist),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	initMemBlockList(fmemblocks->tinylist, TINY);
	initMemBlockList(fmemblocks->smalllist, SMALL);
	initMemBlockList(fmemblocks->largelist, LARGE);
	return (fmemblocks);
}
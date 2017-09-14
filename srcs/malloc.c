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

t_fmemblocks		*g_firstmemblocks = NULL;

void			*malloc(size_t size)
{
	if (g_firstmemblocks == NULL)
		mapFirstMemBlocks();
	size_t i = size;
	i = 3;
	return ((void *)i);
}
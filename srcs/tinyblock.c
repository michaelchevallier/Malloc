/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:21:39 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/18 11:21:49 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			*tinyblock(t_memblock *list)
{
		int		i;
		t_memblock *tmplist;

		i = 0;
		tmplist = list;
		while (tmplist->alloted_mem[i] != 0)
		{
			i++;
			if (i == BLOCKDIV)
			{
				if ((tmplist = tmplist->next) == NULL)
					return (NULL);
				i = 0;
			}
		}

}
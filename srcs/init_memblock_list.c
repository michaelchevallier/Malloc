/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memblock_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:40:11 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:40:18 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		init_memblock_list(t_memblocklist *list, t_blocktype type)
{
	if (type == TINY && set_tiny(list) == -1)
		return (-1);
	else if (type == SMALL && set_small(list) == -1)
		return (-1);
	else if (type == LARGE && set_large(list, 0) == -1)
		return (-1);
	else
		return (0);

}
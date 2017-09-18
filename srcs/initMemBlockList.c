/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initMemBlockList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:40:11 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:40:18 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		initMemBlockList(t_memblocklist *list, t_blocktype type)
{
	if (type == TINY && setTiny(list) == -1)
		return (-1);
	else if (type == SMALL && setSmall(list) == -1)
		return (-1);
	else if (type == LARGE && setLarge(list, 0) == -1)
		return (-1);
	else
		return (0);

}
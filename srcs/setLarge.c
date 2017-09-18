/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setLarge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 13:59:14 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/14 13:59:21 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		setLarge(t_memblocklist *list, size_t size)
{
	list->starting_address = (void *)mmap(0, size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1 , 0);
	if (list->starting_address == MAP_FAILED)
		return (-1);
	list->type = LARGE;
	list->next = NULL;
	return (0);
}

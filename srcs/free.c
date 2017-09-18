/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:31:20 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/13 16:31:43 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		free(void *ptr)
{
	printf("**************************FREE***********************\n");
	if (ptr == NULL)
		return ;
	findPtr(ptr);
}

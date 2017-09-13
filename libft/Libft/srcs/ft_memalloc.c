/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:41:56 by mpaincha          #+#    #+#             */
/*   Updated: 2015/11/27 10:41:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size == 0)
		return (NULL);
	mem = (void *)malloc(sizeof(void) * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

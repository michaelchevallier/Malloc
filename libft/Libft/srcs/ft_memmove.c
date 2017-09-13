/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:07:30 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/03 15:51:45 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*src_tmp;

	src_tmp = (void *)malloc(sizeof(void) * len);
	if (src_tmp == NULL)
		return (NULL);
	ft_memcpy(src_tmp, src, len);
	ft_memcpy(dst, src_tmp, len);
	free(src_tmp);
	return (dst);
}

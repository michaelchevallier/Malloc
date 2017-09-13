/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <mpaincha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:25:25 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/04 10:44:37 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	c2 = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n > i && src1[i] != c2)
	{
		dst1[i] = src1[i];
		i++;
	}
	if (n == i)
		return (NULL);
	if (src1[i] == c2)
	{
		dst1[i] = src1[i];
		i++;
	}
	return ((void *)&dst1[i]);
}

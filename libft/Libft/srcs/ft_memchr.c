/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <mpaincha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:33:04 by mpaincha          #+#    #+#             */
/*   Updated: 2015/11/26 12:21:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*s1;

	i = 0;
	c1 = (unsigned char)c;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:19:25 by mpaincha          #+#    #+#             */
/*   Updated: 2015/11/25 18:07:07 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (i < n)
		str[i++] = 0;
	return (s);
}

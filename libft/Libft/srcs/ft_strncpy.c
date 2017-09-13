/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:26:24 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 11:56:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (n > i && src[i] != '\0')
	{
		dst[i] = (char)src[i];
		i++;
	}
	if (n > i)
	{
		while (n > i)
			dst[i++] = '\0';
	}
	if (n < i)
		dst[i] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 10:43:07 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/09 10:43:11 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_itoabase(int n, size_t base)
{
	char			*str;
	unsigned int	nb;
	size_t			len;

	len = ft_intlenbase(n, base);
	nb = (unsigned int)n;
	str = ft_strnew(len + 1);
	if (base == 10 && n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (nb != 0)
	{
		if (base > 10 && nb % base >= 10)
			str[--len] = (nb % base) + 55;
		else
			str[--len] = (nb % base) + 48;
		nb = nb / base;
	}
	return (str);
}

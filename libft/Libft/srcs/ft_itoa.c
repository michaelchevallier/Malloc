/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:38:51 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 14:21:42 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				len;

	len = ft_intlen(n);
	nb = (unsigned int)n;
	str = ft_strnew(len + 1);
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (nb != 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

static size_t		ft_intlen_imax(intmax_t n, size_t base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (base == 10 && n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char				*ft_itoa_imax(intmax_t n)
{
	char			*str;
	unsigned int	nb;
	size_t			len;

	len = ft_intlen_imax(n, 10);
	nb = (unsigned int)n;
	str = ft_strnew(len + 1);
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
		str[--len] = '0';
	while (nb != 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

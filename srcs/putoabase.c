/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putoabase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:20:50 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/19 15:21:26 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static size_t		putoabase_intlen(uintmax_t n, size_t base)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

void				putoabase(uintmax_t n, size_t base)
{
	size_t			len;
	uintmax_t		ncpy;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	ncpy = n;
	len = putoabase_intlen(n, base);
	if (n == 0)
		ft_putchar('0');
	while (i < len)
	{
		while (j++ < len - 1)
			n = n / base;
		if (base > 10 && n % base >= 10)
			ft_putchar((n % base) + 55);
		else
			ft_putchar((n % base) + 48);
		n = ncpy;
		j = ++i;
	}
}
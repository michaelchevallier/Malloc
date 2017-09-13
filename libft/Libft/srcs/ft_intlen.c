/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:55:40 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/03 17:55:42 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_intlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

size_t		ft_intlenbase(int n, size_t base)
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

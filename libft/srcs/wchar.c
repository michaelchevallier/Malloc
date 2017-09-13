/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:31:57 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/17 16:31:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mask(wchar_t c)
{
	if (c <= 127)
		return (fill_mask(c));
	else if (c <= 2047)
		return (fill_maska(c));
	else if (c <= 65535)
		return (fill_maskb(c));
	else
		return (fill_maskc(c));
}

char	*ft_wchar_str(t_elem *tmpa)
{
	char		*str;
	wchar_t		*arg;
	size_t		i;
	size_t		oct;

	i = 0;
	oct = 0;
	arg = (wchar_t *)ARG->arg;
	str = ft_strnew(0);
	str[0] = '\0';
	if (SPREC.pt != 0)
	{
		while (arg[i] != '\0' && oct < SPREC.n)
			str = ft_strjoinandfree(str, mask_prec(arg[i++], tmpa, &oct), 3);
	}
	else
	{
		while (arg[i] != '\0')
			str = ft_strjoinandfree(str, mask(arg[i++]), 3);
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mask.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:31:57 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/17 16:31:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fill_mask(wchar_t nb)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = nb;
	str[1] = '\0';
	return (str);
}

char	*fill_maska(wchar_t nb)
{
	t_mask		mask;
	char		*str;

	ini_mask(&mask);
	str = ft_strnew(2);
	mask.a = nb & 0x3F;
	nb = nb << 2;
	mask.b = nb & 0x1F00;
	mask.new_nb = mask.b | mask.a | 0xC080;
	str[0] = mask.new_nb >> 8;
	str[1] = mask.new_nb;
	str[2] = '\0';
	return (str);
}

char	*fill_maskb(wchar_t nb)
{
	t_mask		mask;
	char		*str;

	ini_mask(&mask);
	str = ft_strnew(3);
	mask.a = nb & 0x3F;
	nb = nb << 2;
	mask.b = nb & 0x3F00;
	nb = nb << 2;
	mask.c = nb & 0xF0000;
	mask.new_nb = mask.b | mask.a | mask.c | 0xE08080;
	str[0] = mask.new_nb >> 16;
	str[1] = mask.new_nb >> 8;
	str[2] = mask.new_nb;
	str[3] = '\0';
	return (str);
}

char	*fill_maskc(wchar_t nb)
{
	t_mask		mask;
	char		*str;

	ini_mask(&mask);
	str = ft_strnew(4);
	mask.a = nb & 0x3F;
	nb = nb << 2;
	mask.b = nb & 0x3F00;
	nb = nb << 2;
	mask.c = nb & 0x3F0000;
	nb = nb << 2;
	mask.d = nb & 0x70000000;
	mask.new_nb = mask.a | mask.b | mask.c | mask.d | 0xF0808080;
	str[0] = mask.new_nb >> 24;
	str[1] = mask.new_nb >> 16;
	str[2] = mask.new_nb >> 8;
	str[3] = mask.new_nb;
	str[4] = '\0';
	return (str);
}

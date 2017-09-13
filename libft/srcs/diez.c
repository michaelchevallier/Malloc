/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diez.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:26:12 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/22 11:26:14 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diez_o(char **str)
{
	char	*tmp;

	tmp = ft_strjoinandfree("0", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	diez_hexaupper(char **str)
{
	char	*tmp;

	tmp = ft_strjoinandfree("0X", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	diez_hexaupper_zero(char **str, size_t len, t_elem *tmpa)
{
	char	*tmp;

	tmp = NULL;
	if (SFLAGS.width > len)
	{
		if (SFLAGS.width - len == 1)
		{
			(*str)[0] = 'X';
			tmp = ft_strjoinandfree("0", *str, 2);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		else
		{
			(*str)[0] = '0';
			(*str)[1] = 'X';
		}
	}
	else
	{
		tmp = ft_strjoinandfree("0X", *str, 2);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

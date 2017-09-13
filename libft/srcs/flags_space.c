/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:41:33 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 11:41:34 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_beforewidth(char **str)
{
	char	*tmp;

	tmp = NULL;
	if ((*str)[0] != '-')
	{
		tmp = ft_strjoinandfree(" ", *str, 2);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

void	space_afterwidth(t_elem *tmpa, char **str, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if ((*str)[0] != '-')
	{
		if (SFLAGS.width > len)
		{
			(*str)[0] = ' ';
			ft_strdel(&tmp);
		}
		else
		{
			tmp = ft_strjoinandfree(" ", *str, 2);
			*str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
	}
}

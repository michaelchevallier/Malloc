/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:19:44 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/10 18:19:46 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptr_without_zero(t_elem *tmpa, char **str)
{
	char	*tmp;

	tmp = ft_strjoinandfree("0x", *str, 2);
	*str = ft_strdup(tmp);
	ft_strdel(&tmp);
	if (SFLAGS.width != 0)
		width(tmpa, str);
}

static void		ptr_with_zero(t_elem *tmpa, char **str)
{
	char	*tmp;

	tmp = NULL;
	if (SFLAGS.width != 0 && SFLAGS.width > SPREC.n)
	{
		width(tmpa, str);
		tmp = ft_strsub(*str, 2, ft_strlen(*str) - 2);
		ft_strdel(str);
		tmp = ft_strjoinandfree("0x", tmp, 2);
		*str = ft_strdup(tmp);
	}
	else
	{
		tmp = ft_strjoinandfree("0x", *str, 2);
		*str = ft_strdup(tmp);
	}
	ft_strdel(&tmp);
}

void			ft_ptr(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	*str = ft_itoabase_uimax((uintmax_t)ARG->arg, 16);
	if (ft_atoi(*str) == 0 && SPREC.pt == 1)
	{
		ft_strdel(str);
		*str = ft_strdup("");
	}
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.zero == 0)
		ptr_without_zero(tmpa, str);
	else
		ptr_with_zero(tmpa, str);
	ft_strlower(str);
}

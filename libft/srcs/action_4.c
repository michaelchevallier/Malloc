/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 12:55:19 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/23 12:55:21 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_negative(t_elem *tmpa, char **str)
{
	char		*tmp;
	size_t		len;

	tmp = ft_strsub(*str, 1, ft_strlen(*str) - 1);
	len = ft_strlen(*str);
	ft_strdel(str);
	if (SPREC.n != 0)
		prec_doux(tmpa, &tmp);
	if (SFLAGS.zero == 0)
	{
		minus_space(tmpa, &tmp, len);
		if (SFLAGS.width != 0)
			width(tmpa, &tmp);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
	{
		if (SFLAGS.width != 0)
			width(tmpa, &tmp);
		minus_zero(tmpa, &tmp, len);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

static void		positive_without_zero(t_elem *tmpa, char **str, size_t len)
{
	if (SFLAGS.plus == 1)
		plus_space(tmpa, str, len);
	if (SFLAGS.width != 0)
	{
		if (SFLAGS.space == 1)
			space_beforewidth(str);
		width(tmpa, str);
	}
	else
	{
		if (SFLAGS.space == 1)
			space_beforewidth(str);
	}
}

static void		positive_with_zero(t_elem *tmpa, char **str, size_t len)
{
	if (SFLAGS.width != 0)
	{
		width(tmpa, str);
		if (SFLAGS.space == 1)
			space_afterwidth(tmpa, str, len);
	}
	else
	{
		if (SFLAGS.space == 1)
			space_beforewidth(str);
	}
	if (SFLAGS.plus == 1)
		plus_zero(tmpa, str, len);
}

static void		ft_positive(t_elem *tmpa, char **str)
{
	size_t		len;

	if (SPREC.pt != 0)
		prec_doux(tmpa, str);
	len = ft_strlen(*str);
	if (SFLAGS.zero == 0)
		positive_without_zero(tmpa, str, len);
	else
		positive_with_zero(tmpa, str, len);
}

void			ft_dec(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	*str = mod_dec(tmpa);
	if (ft_atoi(*str) == 0 && SPREC.pt == 1)
	{
		ft_strdel(str);
		*str = ft_strdup("");
		ft_positive(tmpa, str);
	}
	else if ((*str)[0] == '-')
		ft_negative(tmpa, str);
	else
		ft_positive(tmpa, str);
}

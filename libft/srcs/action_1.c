/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:19:44 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/10 18:19:46 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_elem *tmpa, char **str, int *cpt_null)
{
	if (ARG->arg == NULL)
	{
		*str = ft_strdup("");
		*cpt_null = *cpt_null + 1;
	}
	else
		*str = mod_char(tmpa);
	if (SFLAGS.width != 0)
		width(tmpa, str);
}

void	ft_string(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	if (ARG->arg == NULL)
		*str = ft_strdup("(null)");
	else
		*str = mod_string(tmpa);
	if (SMOD.l != 1 && SPREC.pt != 0)
		prec_s(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
}

void	ft_octal(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	if (ARG->arg == NULL)
		*str = ft_strdup("");
	else
		*str = mod_octal(tmpa);
	if (SFLAGS.diez == 1)
		diez_o(str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
	if ((*str)[0] == '\0' && SPREC.pt == 0)
	{
		ft_strdel(str);
		*str = ft_strdup("0");
	}
}

void	ft_unsig(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	*str = mod_unsig(tmpa);
	if (ft_atoi(*str) == 0 && SPREC.pt == 1)
	{
		ft_strdel(str);
		*str = ft_strdup("");
	}
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
}

void	ft_unknown(t_elem *tmpa, char **str, int *cpt_null)
{
	(void)cpt_null;
	*str = ft_strdup(ARG->spec);
	if (SFLAGS.width != 0)
		width(tmpa, str);
}

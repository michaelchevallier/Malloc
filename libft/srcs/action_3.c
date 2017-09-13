/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:19:44 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/10 18:19:46 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hexaupper_without_zero(t_elem *tmpa, char **str)
{
	if (SFLAGS.diez == 1 && ARG->arg != NULL)
		diez_hexaupper(str);
	if (SFLAGS.width != 0)
		width(tmpa, str);
}

static void		hexaupper_with_zero(t_elem *tmpa, char **str, size_t len)
{
	if (SFLAGS.width != 0)
		width(tmpa, str);
	if (SFLAGS.diez == 1 && ARG->arg != NULL)
		diez_hexaupper_zero(str, len, tmpa);
}

void			ft_hexalower(t_elem *tmpa, char **str, int *cpt_null)
{
	ft_hexaupper(tmpa, str, cpt_null);
	ft_strlower(str);
}

void			ft_hexaupper(t_elem *tmpa, char **str, int *cpt_null)
{
	size_t	len;

	(void)cpt_null;
	if (ARG->arg == NULL)
		*str = ft_strdup("");
	else
		*str = mod_hexa(tmpa);
	len = ft_strlen(*str);
	if (SPREC.n != 0)
		prec_doux(tmpa, str);
	if (SFLAGS.zero == 0)
		hexaupper_without_zero(tmpa, str);
	else
		hexaupper_with_zero(tmpa, str, len);
	if ((*str)[0] == '\0' && SPREC.pt == 0)
	{
		ft_strdel(str);
		*str = ft_strdup("0");
	}
}

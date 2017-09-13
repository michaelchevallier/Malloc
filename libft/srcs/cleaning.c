/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:54:49 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 12:54:51 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cleanarg(t_dbllist *lst_arg)
{
	t_elem	*tmpa;

	tmpa = lst_arg->head;
	while (tmpa != NULL)
	{
		if ((ARG->spec[0] != 'x' && ARG->spec[0] != 'X' && ARG->spec[0] != 'o')
		&& ARG->flags.diez == 1)
			ARG->flags.diez = 0;
		if (ARG->flags.zero == 1 && ARG->flags.minus == 1)
			ARG->flags.zero = 0;
		if (ARG->prec.pt != 0 && ARG->flags.zero == 1 && (ARG->spec[0] == 'd'
		|| ARG->spec[0] == 'i' || ARG->spec[0] == 'o' || ARG->spec[0] == 'u'
		|| ARG->spec[0] == 'x' || ARG->spec[0] == 'X'))
			ARG->flags.zero = 0;
		if (ARG->flags.plus == 1 && ARG->flags.space == 1)
			ARG->flags.space = 0;
		tmpa = tmpa->next;
	}
}

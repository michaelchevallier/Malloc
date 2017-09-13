/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:22:01 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/13 18:22:02 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_elem	*find_pos(char *spec, t_dbllist *lst_str)
{
	int			found;
	t_elem		*tmps;

	tmps = lst_str->head;
	found = 0;
	while (tmps != NULL && !found)
	{
		if (ft_strequ(SSTR->str, spec) && SSTR->n == 0)
		{
			found = 1;
			SSTR->n = 1;
			break ;
		}
		else
			tmps = tmps->next;
	}
	if (found == 0)
		tmps = NULL;
	return (tmps);
}

void			ft_putlststr(t_dbllist *list, int *oct)
{
	t_elem	*tmps;

	tmps = list->head;
	while (tmps != NULL)
	{
		*oct = *oct + write(1, SSTR->str, ft_strlen(SSTR->str));
		tmps = tmps->next;
	}
}

void			display_percent(int nb, t_dbllist *lst_str)
{
	t_str	sstr;
	int		i;

	ini_sstr(&sstr);
	i = 0;
	if (nb >= 1)
	{
		sstr.str = ft_strnew(nb);
		while (i < nb)
		{
			sstr.str[i] = '%';
			i++;
		}
		sstr.str[i] = '\0';
		ft_lstdbladd(lst_str, &sstr, sizeof(t_str));
	}
}

int				stock_str(const char *format, int i, t_dbllist *lst_str)
{
	t_str	sstr;
	int		start;

	ini_sstr(&sstr);
	start = i;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	sstr.str = ft_strsub(format, start, (i - start));
	sstr.n = 1;
	ft_lstdbladd(lst_str, &sstr, sizeof(t_str));
	return (i - 1);
}

void			transformation(t_dbllist *lst_arg, t_dbllist *lst_str,
				int *cpt_null)
{
	t_elem					*tmpa;
	static const t_action	ft_action[] = {ft_string, ft_ptr, ft_dec, ft_octal,
							ft_unsig, ft_hexalower, ft_hexaupper, ft_char,
							ft_unknown};
	t_action				actions;
	t_elem					*tmps;
	char					*todel;

	tmpa = lst_arg->head;
	tmps = lst_str->head;
	while (tmpa != NULL)
	{
		actions = ft_action[ARG->action];
		tmps = find_pos(ARG->spec, lst_str);
		todel = SSTR->str;
		actions(tmpa, &SSTR->str, cpt_null);
		ft_strdel(&todel);
		tmpa = tmpa->next;
	}
}

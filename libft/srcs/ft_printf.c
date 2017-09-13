/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:12:51 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/11 11:12:54 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		recover(const char *format, t_dbllist *lst_arg,
				t_dbllist *lst_str, int *i)
{
	if (recover_arg(format, lst_arg, lst_str, i) == -1)
	{
		ft_lstdbldel_arg(lst_arg);
		ft_memdel((void **)&lst_arg);
		ft_lstdbldel_str(lst_str);
		ft_memdel((void **)&lst_str);
		free(lst_arg);
		return (-1);
	}
	return (1);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_dbllist		*lst_arg;
	t_dbllist		*lst_str;
	t_counters		counters;

	ini_counters(&counters);
	lst_arg = ft_lstdblnew();
	lst_str = ft_lstdblnew();
	va_start(ap, format);
	if (recover(format, lst_arg, lst_str, &counters.i) == -1)
		return (-1);
	recover_param(ap, lst_arg);
	cleanarg(lst_arg);
	transformation(lst_arg, lst_str, &counters.cpt_null);
	if (lst_str->head)
		ft_putlststr(lst_str, &counters.oct);
	if (counters.cpt_null != 0)
		counters.oct = counters.oct + counters.cpt_null;
	ft_lstdbldel_arg(lst_arg);
	ft_memdel((void **)&lst_arg);
	ft_lstdbldel_str(lst_str);
	ft_memdel((void **)&lst_str);
	va_end(ap);
	return (counters.oct);
}

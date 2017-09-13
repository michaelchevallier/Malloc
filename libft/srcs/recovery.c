/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 11:01:37 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/27 11:01:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		split_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		int *i)
{
	t_arg		sarg;
	t_str		sstr;
	int			ret;

	ini_sarg(&sarg);
	ini_sstr(&sstr);
	if ((ret = checks(format, i, &sarg)) == -1)
		return (-1);
	*i = *i + 1;
	if (ret == -2)
	{
		ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
		sstr.str = ft_strdup(sarg.spec);
		ft_lstdbladd(lst_str, &sstr, sizeof(t_str));
		recover_arg(format, lst_arg, lst_str, i);
	}
	else
	{
		ft_lstdbladd(lst_arg, &sarg, sizeof(t_arg));
		sstr.str = ft_strdup(sarg.spec);
		ft_lstdbladd(lst_str, &sstr, sizeof(t_str));
		if (format[*i] != '\0')
			recover_arg(format, lst_arg, lst_str, i);
	}
	return (1);
}

void	recover_param(va_list ap, t_dbllist *lst_arg)
{
	void		*arg;
	t_elem		*tmpa;

	tmpa = lst_arg->head;
	arg = (void *)1;
	while (tmpa != NULL)
	{
		arg = va_arg(ap, void *);
		ARG->arg = arg;
		tmpa = tmpa->next;
	}
}

int		percent(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
		int *i)
{
	int		percent;

	percent = 1;
	while (format[*i + 1] == '%')
	{
		percent++;
		*i = *i + 1;
	}
	if (percent > 1)
	{
		display_percent((percent / 2), lst_str);
		if (percent % 2 == 0)
			return (0);
	}
	*i = *i + 1;
	if (format[*i] != '\0')
	{
		if (split_arg(format, lst_arg, lst_str, i) == -1)
		{
			recover_arg(format, lst_arg, lst_str, i);
			return (1);
		}
	}
	return (1);
}

int		recover_arg(const char *format, t_dbllist *lst_arg, t_dbllist *lst_str,
					int *i)
{
	int		ret;

	while (format && *i < (int)ft_strlen(format))
	{
		if (format[*i] == '%')
		{
			ret = percent(format, lst_arg, lst_str, i);
			if (ret == -1)
				return (-1);
		}
		else if (*i < (int)ft_strlen(format) && ft_isascii(format[*i]))
			*i = stock_str(format, *i, lst_str);
		*i = *i + 1;
	}
	return (1);
}

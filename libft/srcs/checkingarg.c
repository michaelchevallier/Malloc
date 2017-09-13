/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:31 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 18:40:33 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			saveflags(char find, t_arg *sarg)
{
	if (find == '#')
		sarg->flags.diez = 1;
	else if (find == '0')
		sarg->flags.zero = 1;
	else if (find == '-')
		sarg->flags.minus = 1;
	else if (find == '+')
		sarg->flags.plus = 1;
	else if (find == ' ')
		sarg->flags.space = 1;
}

int					check_flags(const char *format, int *i, t_arg *sarg)
{
	while (format[*i] != '\0' && ft_strchr(FLAGS, format[*i]))
	{
		saveflags(format[*i], sarg);
		*i = *i + 1;
	}
	return (1);
}

int					check_width(char *str, t_arg *sarg, int *i)
{
	int		width;

	width = 0;
	if ((width = ft_atoi(str)))
	{
		sarg->flags.width = width;
		*i = *i + ft_intlen(width);
		ft_strdel(&str);
		return (1);
	}
	else
	{
		ft_strdel(&str);
		return (0);
	}
}

int					checks(const char *format, int *i, t_arg *sarg)
{
	check_flags(format, i, sarg);
	check_width(ft_strsub(format, *i, ft_strlen(format) - *i), sarg, i);
	if (format[*i] == '.')
		check_prec(format, i, sarg);
	check_mod(format, i, sarg);
	if (check_spec(format, i, sarg))
		return (1);
	else
	{
		if (ft_isupper(format[*i]))
		{
			sarg->spec[0] = format[*i];
			sarg->action = 8;
			return (-2);
		}
		else
		{
			ft_strdel(&sarg->spec);
			return (-1);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingspecprec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:31 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 18:40:33 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			define_action(char *spec, char find)
{
	size_t		i;

	i = 0;
	while (spec[i] != '\0')
	{
		if (spec[i] == find)
			return (i);
		i++;
	}
	return (-1);
}

int					check_prec(const char *format, int *i, t_arg *sarg)
{
	int		numb;
	char	*str;

	numb = 0;
	sarg->prec.pt = 1;
	str = ft_strsub(format, *i + 1, ft_strlen(format) - *i - 1);
	if ((numb = ft_atoi(str)) >= 0)
	{
		sarg->prec.n = numb;
		if (numb > 0 || (numb == 0 && str[0] == '0'))
			*i = *i + ft_intlen(numb) + 1;
		else
			*i = *i + 1;
	}
	else
	{
		sarg->prec.n = 0;
		*i = *i + 1;
	}
	ft_strdel(&str);
	return (1);
}

int					check_spec(const char *format, int *i, t_arg *sarg)
{
	if (ft_strlen(sarg->spec) == 0 && ft_strchr(SPEC, ft_tolower(format[*i])))
	{
		sarg->spec[0] = format[*i];
		sarg->spec[1] = '\0';
		sarg->action = define_action(SPEC, format[*i]);
		if (ft_isupper(format[*i]) && format[*i] != 'X')
		{
			reini_mod(sarg);
			sarg->spec[0] = ft_tolower(format[*i]);
			sarg->action = define_action(SPEC, sarg->spec[0]);
		}
		else if (format[*i] == 'p')
			sarg->mod.j = 1;
		return (1);
	}
	if (format[*i] == 'i')
	{
		sarg->spec[0] = 'd';
		sarg->action = define_action(SPEC, 'd');
		return (1);
	}
	return (0);
}

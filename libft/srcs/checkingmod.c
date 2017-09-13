/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:40:31 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/14 18:40:33 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			savemod(char find, t_arg *sarg)
{
	if (find == 'h')
		sarg->mod.h++;
	else if (find == 'l')
		sarg->mod.l++;
	else if (find == 'j')
		sarg->mod.j = 1;
	else if (find == 'z')
		sarg->mod.z = 1;
}

static int			errormod(t_arg *sarg)
{
	int		i;

	i = 0;
	if (sarg->mod.h > 0)
		i++;
	if (sarg->mod.l > 0)
		i++;
	if (sarg->mod.j > 0)
		i++;
	if (sarg->mod.z > 0)
		i++;
	if (i > 1)
		return (-1);
	else if (i == 0)
		return (0);
	return (1);
}

int					check_mod(const char *format, int *i, t_arg *sarg)
{
	while (format[*i] != '\0' && ft_strchr(MOD, format[*i]))
	{
		savemod(format[*i], sarg);
		*i = *i + 1;
	}
	if (sarg->mod.h > 0)
	{
		if (sarg->mod.h % 2 == 0)
			sarg->mod.h = 2;
		else
			sarg->mod.h = 1;
	}
	else if (sarg->mod.l > 0)
	{
		if (sarg->mod.l % 2 == 0)
			sarg->mod.l = 2;
		else
			sarg->mod.l = 1;
	}
	return (errormod(sarg));
}

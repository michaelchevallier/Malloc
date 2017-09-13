/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:13:17 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/12 17:13:20 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	len_width_null(t_elem *tmpa, size_t *len)
{
	if (ARG->spec[0] == 'c' || ARG->spec[0] == '%'
		|| !(ft_strchr(SPEC, ARG->spec[0])))
		*len = 1;
	if (ARG->spec[0] == 'd')
	{
		if (SFLAGS.space == 0)
		{
			if (SPREC.pt != 0)
				*len = SPREC.n;
			else
				*len = 1;
		}
		else
		{
			if (SPREC.pt != 0)
				*len = SPREC.n;
			else
				*len = 2;
		}
	}
}

static	size_t	len_width(t_elem *tmpa, char **str)
{
	size_t	len;

	len = 0;
	if (ARG->arg == NULL && ft_strlen(*str) == 0)
		len_width_null(tmpa, &len);
	else
		len = ft_strlen(*str);
	return (len);
}

static	void	which_add(t_elem *tmpa, char *tadd)
{
	if (SFLAGS.zero == 0)
		*tadd = ' ';
	else
		*tadd = '0';
}

void			width(t_elem *tmpa, char **str)
{
	char	*tmp;
	char	*add;
	size_t	i;
	size_t	len;
	char	tadd;

	tmp = NULL;
	add = NULL;
	i = 0;
	if (SFLAGS.width > (len = len_width(tmpa, str)))
	{
		add = ft_strnew(SFLAGS.width - len);
		which_add(tmpa, &tadd);
		while (i < (SFLAGS.width - len))
			add[i++] = tadd;
		add[i] = '\0';
		if (SFLAGS.minus == 0)
			tmp = ft_strjoinandfree(add, *str, 3);
		else
			tmp = ft_strjoinandfree(*str, add, 3);
		*str = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}

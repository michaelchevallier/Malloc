/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:31:57 by mpaincha          #+#    #+#             */
/*   Updated: 2016/02/17 16:31:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*oct1(wchar_t c, t_elem *tmpa, size_t *oct)
{
	char	*end;

	end = ft_strnew(0);
	end[0] = '\0';
	*oct = *oct + 1;
	if (*oct <= SPREC.n)
	{
		ft_strdel(&end);
		return (fill_mask(c));
	}
	else
		return (end);
}

static	char	*oct2(wchar_t c, t_elem *tmpa, size_t *oct)
{
	char	*end;

	end = ft_strnew(0);
	end[0] = '\0';
	*oct = *oct + 2;
	if (*oct <= SPREC.n)
	{
		ft_strdel(&end);
		return (fill_maska(c));
	}
	else
		return (end);
}

static	char	*oct3(wchar_t c, t_elem *tmpa, size_t *oct)
{
	char	*end;

	end = ft_strnew(0);
	end[0] = '\0';
	*oct = *oct + 3;
	if (*oct <= SPREC.n)
	{
		ft_strdel(&end);
		return (fill_maskb(c));
	}
	else
		return (end);
}

static	char	*oct4(wchar_t c, t_elem *tmpa, size_t *oct)
{
	char	*end;

	end = ft_strnew(0);
	end[0] = '\0';
	*oct = *oct + 4;
	if (*oct <= SPREC.n)
	{
		ft_strdel(&end);
		return (fill_maskc(c));
	}
	else
		return (end);
}

char			*mask_prec(wchar_t c, t_elem *tmpa, size_t *oct)
{
	if (c <= 127)
		return (oct1(c, tmpa, oct));
	else if (c <= 2047)
		return (oct2(c, tmpa, oct));
	else if (c <= 65535)
		return (oct3(c, tmpa, oct));
	else
		return (oct4(c, tmpa, oct));
}

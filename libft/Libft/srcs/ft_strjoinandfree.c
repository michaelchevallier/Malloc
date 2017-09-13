/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinandfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:36:33 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 11:39:56 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoinandfree(char *s1, char *s2, int tofree)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	if (tofree == 1)
		ft_strdel(&s1);
	else if (tofree == 2)
		ft_strdel(&s2);
	else if (tofree == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}

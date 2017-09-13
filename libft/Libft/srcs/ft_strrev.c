/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:39:10 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 16:34:54 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	int		ilen;
	char	c;

	i = 0;
	len = ft_strlen(str);
	ilen = len - 1;
	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[ilen];
		str[ilen] = c;
		i++;
		ilen--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:38:58 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/03 17:55:27 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_words(char const *s, char c)
{
	int		i;
	int		count;
	int		ok;

	i = 0;
	count = 0;
	ok = 1;
	while (s[i])
	{
		if (s[i] != c && ok)
		{
			count++;
			ok = 0;
		}
		else if (s[i] == c)
			ok = 1;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <mpaincha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:40:38 by mpaincha          #+#    #+#             */
/*   Updated: 2015/11/26 11:55:52 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ptr = (char *)&s[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}

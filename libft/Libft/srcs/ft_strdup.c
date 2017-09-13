/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:51:15 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/03 15:52:28 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strdup;

	if (s1 != NULL)
	{
		strdup = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
		if (strdup == NULL)
			return (NULL);
		return (ft_strcpy(strdup, s1));
	}
	return (NULL);
}

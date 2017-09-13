/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:54:58 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 11:38:53 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, (char *)&s[start], len);
	str[len + 1] = '\0';
	return (str);
}

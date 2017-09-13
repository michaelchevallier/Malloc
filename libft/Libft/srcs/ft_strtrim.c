/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:08:22 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/02 11:28:13 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	lg_str;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	lg_str = 0;
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	lg_str = ft_strlen(s + i) - 1;
	while (s[i] && (s[lg_str + i] == '\t' || s[lg_str + i] == '\n'
		|| s[lg_str + i] == ' '))
		lg_str--;
	str = ft_strnew(lg_str + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, s + i, lg_str + 1);
	return (str);
}

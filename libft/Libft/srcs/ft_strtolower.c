/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvignau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:04:15 by kvignau           #+#    #+#             */
/*   Updated: 2016/11/28 11:04:21 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtolower(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

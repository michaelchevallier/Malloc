/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2dtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:43:23 by mchevall          #+#    #+#             */
/*   Updated: 2016/10/05 14:43:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_free2dtab(void **tab, int tab_size)
{
	int		i;

	i = 0;
	while (i < tab_size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

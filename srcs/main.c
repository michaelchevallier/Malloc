/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 15:38:28 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/13 15:38:30 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int main(int argc, char **argv)
{
	int				i;
	char			**j;
	struct			rlimit r1;

	i = argc;
	j = argv;

	malloc(1);
	malloc(10);
	malloc(100);
	malloc(1000);
	malloc(1000);
	malloc(10000);
	malloc(10000);
	malloc(100000);
	malloc(1000000);
	printf("pagesize %d \n", getpagesize());
	printf("limit %d \n", getrlimit(RLIMIT_DATA, &r1));
	return (0);
}
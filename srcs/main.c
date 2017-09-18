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
	int				z;
	char			**y;
	struct			rlimit r1;
	int *a;
	int *b;
	int *c;
	int *d;
	int *e;
	int *f;
	int *g;
	int *h;
	int *i;
	int *j;

	z = argc;
	y = argv;

	a = malloc(1 * sizeof(int));
	b = malloc(10 * sizeof(int));
	c = malloc(100* sizeof(int));
	d = malloc(1000* sizeof(int));
	e = malloc(1000* sizeof(int));
	f = malloc(10000* sizeof(int));
	g = malloc(10000* sizeof(int));
	h = malloc(10000* sizeof(int));
	i = malloc(100000* sizeof(int));
	j = malloc(1000000* sizeof(int));

	printf("a : ");
	free(a);
	printf("\nb : ");
	free(b);
	printf("\nc : ");
	free(c);
	printf("\nd : ");
	free(d);
	printf("\ne : ");
	free(e);
	printf("\nf : ");
	free(f);
	printf("\ng : ");
	free(g);
	printf("\nh : ");
	free(h);
	printf("\ni : ");
	free(i);
	printf("\nj : ");
	free(j);
	// printf("pagesize %d \n", getpagesize());
	// printf("limit %d \n", getrlimit(RLIMIT_DATA, &r1));
	return (0);
}
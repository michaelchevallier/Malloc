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

int main(void)
{
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

	a = malloc(1 * sizeof(int));
	show_alloc_mem();
	printf("%p\n", a);

	b = malloc(10 * sizeof(int));
	show_alloc_mem();
	printf("%p\n", b);

	c = malloc(100* sizeof(int));
	show_alloc_mem();
	printf("%p\n", c);

	d = malloc(1000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", d);

	e = malloc(1000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", e);

	f = malloc(10000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", f);

	g = malloc(10000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", g);

	h = malloc(10000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", h);

	i = malloc(100000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", i);

	j = malloc(1000000* sizeof(int));
	show_alloc_mem();
	printf("%p\n", j);
	// printf("\na:");
	// realloc(a, 10);
	// printf("\nb:");
	// realloc(b, 100);
	// printf("\nc:");
	// realloc(c, 1000);
	// printf("\nd:");
	// realloc(d, 10000);
	// printf("\ne:");
	// realloc(e, 10000);
	// printf("\nf:");
	// realloc(f, 100000);
	// printf("\ng:");
	// realloc(g, 100000);
	// printf("\nh:");
	// realloc(h, 100000);
	// printf("\ni:");
	// realloc(i, 1000000);
	// printf("\nj:");
	// realloc(j, 10000000);
	// printf("\n");


	// show_alloc_mem();

	// printf("a : ");
	// free(a);
	// printf("\nb : ");
	// free(b);
	// printf("\nc : ");
	// free(c);
	// printf("\nd : ");
	// free(d);
	// printf("\ne : ");
	// free(e);
	// printf("\nf : ");
	// free(f);
	// printf("\ng : ");
	// free(g);
	// printf("\nh : ");
	// free(h);
	// printf("\ni : ");
	// free(i);
	// printf("\nj : ");
	// free(j);
	// printf("pagesize %d \n", getpagesize());
	// printf("limit %d \n", getrlimit(RLIMIT_DATA, &r1));
	return (0);
}
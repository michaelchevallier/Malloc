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

	// show_alloc_mem();
	// for (int i = 0; i < 101; i++)
	// 	malloc(1);

	a = malloc(1);
	show_alloc_mem();
	// printf("%p\n\n                                                  ######################################                                        \n\n", a);

	b = malloc(10);
	// show_alloc_mem();
	// printf("%p\n\n", b);

	c = malloc(100);
	// show_alloc_mem();
	// printf("%p\n\n", c);

	d = malloc(1000);
	// show_alloc_mem();
	// printf("%p\n\n", d);

	e = malloc(1000);
	// show_alloc_mem();
	// printf("%p\n\n", e);

	f = malloc(10000);
	// show_alloc_mem();
	// printf("%p\n\n", f);

	g = malloc(10000);
	// show_alloc_mem();
	// printf("%p\n\n", g);

	h = malloc(10000);
	// show_alloc_mem();
	// printf("%p\n\n", h);

	i = malloc(100000);
	// show_alloc_mem();
	// printf("%p\n\n", i);

	j = malloc(1000000);
	// show_alloc_mem();
	// printf("%p\n\n", j);

	// printf ("############################### REALLOC ##########################\n\n");

	// printf("REALLOCING : [a] : %p => 10\n", a);
	a = realloc(a, 10);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [b] : %p => 100\n", b);
	b = realloc(b, 100);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [c] : %p => 1000\n", c);
	c = realloc(c, 1000);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [d] : %p => 10000\n", d);
	d = realloc(d, 10000);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [e] : %p => 10000\n", e);
	e = realloc(e, 10000);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [f] : %p => 100000\n", f);
	f = realloc(f, 100000);
	show_alloc_mem();

	printf("\n\n");

	// printf("REALLOCING : [g] : %p => 100000\n", g);
	g = realloc(g, 100000);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [h] : %p => 100000\n", h);
	h = realloc(h, 100000);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [i] : %p => 1000000\n", i);
	i = realloc(i, 1000000);
	show_alloc_mem();
	printf("\n\n");

	// printf("REALLOCING : [j] : %p => 10000000\n", j);
	j = realloc(j, 10000000);
	show_alloc_mem();
	printf("\n\n");


	// printf("###################################### FREE $$$$$$$$$$$$$$$$$$$$$$$$$ \n\n");

	// printf("FREEING : [a] : %p\n", a);
	free(a);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [b] : %p\n", b);
	free(b);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [c] : %p\n", c);
	free(c);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [d] : %p\n", d);
	free(d);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [e] : %p\n", e);
	free(e);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [f] : %p\n", f);
	free(f);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [g] : %p\n", g);
	free(g);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [h] : %p\n", h);
	free(h);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [i] : %p\n", i);
	free(i);
	show_alloc_mem();
	printf("\n\n");

	// printf("FREEING : [j] : %p\n", j);
	free(j);
	show_alloc_mem();
	printf("\n\n");

		a = malloc(1);
	show_alloc_mem();
	// printf("%p\n\n                                                  ######################################                                        \n\n", a);

	b = malloc(10);
	show_alloc_mem();
	// printf("%p\n\n", b);

	c = malloc(100);
	show_alloc_mem();
	// printf("%p\n\n", c);

	d = malloc(1000);
	show_alloc_mem();
	// printf("%p\n\n", d);

	e = malloc(1000);
	show_alloc_mem();
	// printf("%p\n\n", e);

	f = malloc(10000);
	show_alloc_mem();
	// printf("%p\n\n", f);

	g = malloc(10000);
	// show_alloc_mem();
	// printf("%p\n\n", g);

	h = malloc(10000);
	// show_alloc_mem();
	// printf("%p\n\n", h);

	i = malloc(100000);
	// show_alloc_mem();
	// printf("%p\n\n", i);

	j = malloc(1000000);

	printf("sizeof(t_memblocklist): %lu\n", sizeof(t_memblocklist));
	// printf("pagesize %d \n", getpagesize());
	// printf("limit %d \n", getrlimit(RLIMIT_DATA, &r1));
	return (0);
}
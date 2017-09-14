/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 11:39:03 by mchevall          #+#    #+#             */
/*   Updated: 2017/09/13 14:05:52 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>


#include <stdio.h>


# define BLOCKDIV 100
# define TINYSIZE 100
# define SMALLSIZE 1000

/** Portions of memBlock **/
typedef struct	s_block
{
	int			id;
	int			isused;
	void		*starting_address;
	void		*parent_address;
	size_t		size;
	size_t		alloted_mem;
}				t_block;

/** type: TINY = 0 || SMALL = 1 || LARGE = 2 **/
typedef struct	s_memblock
{
	size_t		size;
	size_t		alloted_mem;
	void		*starting_address;
	t_Block		blocks[BLOCKDIV + 1];
	int			isfull;
	int			type;
}				t_memblock;

typedef struct	s_tinylist
{
	size_t		size;
	t_memblock	*current;
	t_memblock	*next;
	t_memblock	*prev;
	t_memblock	*start;
	t_memblock	*end;
}				t_tinylist;

typedef struct	s_smalllist
{
	size_t		size;
	t_memblock	*current;
	t_memblock	*next;
	t_memblock	*prev;
	t_memblock	*start;
	t_memblock	*end;
}				t_smalllist;

typedef struct	s_largelist
{
	size_t		size;
	t_memblock	*current;
	t_memblock	*next;
	t_memblock	*prev;
	t_memblock	*start;
	t_memblock	*end;
}				t_largelist;

typedef struct	s_fmemblocks
{
	t_tinylist	*tinylist;
	t_smalllist	*smalllist;
	t_largelist	*largelist;
}				t_fmemblocks;

t_fmemblocks	g_firstmemblocks = NULL;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem();

#endif

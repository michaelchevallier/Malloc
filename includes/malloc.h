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
# define PAGESIZE getpagesize()

# define TINYSIZE 10
# define SMALLSIZE 100

typedef enum		e_blocktype
{
					TINY,
					SMALL,
					LARGE
}					t_blocktype;

/** Portions of memBlock **/
typedef struct		s_block
{
	int				id;
	int				isused;
	void			*starting_address;
	void			*parent_address;
	size_t			size;
	size_t			alloted_mem;
}					t_block;

/** type: TINY = 0 || SMALL = 1 || LARGE = 2 **/
typedef struct		s_memblock
{
	size_t			size;
	size_t			alloted_mem;
	void			*starting_address;
	t_block			blocks[BLOCKDIV + 1];
	t_blocktype		type;
	int				isfull;
}					t_memblock;

typedef struct		s_memblocklist
{
	size_t			size;
	t_blocktype		type;
	t_memblock		*current;
	t_memblock		*next;
}					t_memblocklist;

typedef struct		s_fmemblocks
{
	t_memblocklist	*tinylist;
	t_memblocklist	*smalllist;
	t_memblocklist	*largelist;
}					t_fmemblocks;


void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
t_fmemblocks		*mapFirstMemBlocks();
void				initMemBlockList(t_memblocklist *list, t_blocktype type);
void				setTiny(t_memblocklist *list);
void				setSmall(t_memblocklist *list);
void				setLarge(t_memblocklist *list);

#endif
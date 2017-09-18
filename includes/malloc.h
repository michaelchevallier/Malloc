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

# define TINYSIZE 10 * PAGESIZE
# define SMALLSIZE 100 * PAGESIZE
# define TINYBLOCK TINYSIZE / 100
# define SMALLBLOCK SMALLSIZE / 100

typedef enum				e_blocktype
{
							TINY,
							SMALL,
							LARGE
}							t_blocktype;

/** type: TINY = 0 || SMALL = 1 || LARGE = 2 **/

typedef struct				s_memblocklist
{
	void					*starting_address;
	size_t					alloted_mem[BLOCKDIV];
	t_blocktype				type;
	struct s_memblocklist	*next;
}							t_memblocklist;

typedef struct				s_fmemblocks
{
	t_memblocklist			*tinylist;
	t_memblocklist			*smalllist;
	t_memblocklist			*largelist;
}							t_fmemblocks;


void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						show_alloc_mem();
t_fmemblocks				*mapFirstMemBlocks();
void						initMemBlockList(t_memblocklist *list, t_blocktype type);
int							setTiny(t_memblocklist *list);
int							setSmall(t_memblocklist *list);
int							setLarge(t_memblocklist *list, size_t size);
void						*tinyblock(t_memblock *list);
void						*smallblock(t_memblock *list);
void						*largeblock(t_memblock *list, size_t size);
// t_block				initBlock(t_block block, int i, t_memblock *memblock);

//t_fmemblocks		*g_fmem = NULL;

#endif
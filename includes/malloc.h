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
# include "../libft/includes/ft_printf.h"

#include <stdio.h>

# define BLOCKDIV 100
# define PAGESIZE getpagesize()

# define TINYSIZE (size_t)(10 * PAGESIZE)
# define SMALLSIZE (size_t)(100 * PAGESIZE)
# define TBLOCK ((TINYSIZE) / (100))
# define SBLOCK ((SMALLSIZE) / (100))
# define TBLOCKADDR start_add + (i * TBLOCK)
# define SBLOCKADDR start_add + (i * SBLOCK)

typedef enum				e_blocktype
{
							TINY = TINYSIZE,
							SMALL,
							LARGE
}							t_blocktype;

/** type: TINY = 0 || SMALL = 1 || LARGE = 2 **/

typedef struct				s_memblocklist
{
	void					*start_add;
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
void						show_alloc_mem(void);
t_fmemblocks				*mapFirstMemBlocks(void);
int							initMemBlockList(t_memblocklist *list, t_blocktype type);
int							setTiny(t_memblocklist *list);
int							setSmall(t_memblocklist *list);
int							setLarge(t_memblocklist *list, size_t size);
void						*assignBlock(t_memblocklist *list, size_t size);
int							createNewMemBlock(t_memblocklist *list, t_blocktype type);
void						findPtr(void *ptr);
int							isSamePtr(void *ptr1, void *ptr2);
void						putoabase(uintmax_t n, size_t base);
// t_block				initBlock(t_block block, int i, t_memblock *memblock);

extern t_fmemblocks		*g_fmem;

#endif
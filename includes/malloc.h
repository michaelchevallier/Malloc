/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
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
# define BLOCKDIV 100
# define PAGESIZE getpagesize()
# define TINYSIZE (size_t)(25 * PAGESIZE)
# define SMALLSIZE (size_t)(3200 * PAGESIZE)
# define TBLOCK ((TINYSIZE) / (100))
# define SBLOCK ((SMALLSIZE) / (100))
# define TBLOCKADDR start_add + (i * TBLOCK)
# define SBLOCKADDR start_add + (i * SBLOCK)

typedef enum				e_blocktype
{
	TINY,
	SMALL,
	LARGE
}							t_blocktype;

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
t_fmemblocks				*map_first_memblocks(void);
int							init_memblock_list(t_memblocklist *list,
	t_blocktype type);
int							set_tiny(t_memblocklist *list);
int							set_small(t_memblocklist *list);
int							set_large(t_memblocklist *list, size_t size);
void						*assign_block(t_memblocklist *list, size_t size);
int							create_new_memblock(t_memblocklist *list,
	t_blocktype type);
int							is_same_ptr(void *ptr1, void *ptr2);
void						putoabase(uintmax_t n, size_t base);
size_t						printmeminfo(t_memblocklist *list);

extern t_fmemblocks		*g_fmem;
#endif

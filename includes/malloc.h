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

//Portions of memBlock
typedef struct	s_Block
{
	int			id;
	int			isUsed;
	void		*startingAddress;
	void		*parentAddress;
	size_t		size;
	size_t		allotedMem;
}				t_Block;

/* type: TINY = 0 || SMALL = 1 || LARGE = 2 */
typedef struct	s_memBlock
{
	size_t		size;
	size_t		allotedMem;
	void		*startingAddress;
	t_Block		blocks[BLOCKDIV + 1];
	int			isFull;
	int			type;
}				t_memBlock;

typedef struct	s_tinyList
{
	size_t		size;
	t_memBlock	*current;
	t_memBlock	*next;
	t_memBlock	*prev;
	t_memBlock	*start;
	t_memBlock	*end;
}				t_tinyList;

typedef struct	s_smallList
{
	size_t		size;
	t_memBlock	*current;
	t_memBlock	*next;
	t_memBlock	*prev;
	t_memBlock	*start;
	t_memBlock	*end;
}				t_smallList;

typedef struct	s_largeList
{
	size_t		size;
	t_memBlock	*current;
	t_memBlock	*next;
	t_memBlock	*prev;
	t_memBlock	*start;
	t_memBlock	*end;
}				t_largeList;

typedef struct	s_fMemBlocks
{
	t_tinyList	*tinyList;
	t_smallList	*smallList;
	t_largeList	*largeList;
}				t_fMemBlocks;

t_fMemBlocks	firstMemBlocks;

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem();

#endif

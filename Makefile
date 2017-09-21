# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 15:49:31 by mchevall          #+#    #+#              #
#    Updated: 2017/09/21 18:53:51 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE:= $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINKNAME = libft_malloc.so
PRINTF = libft/
PRINTFLIB = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

INC = includes/malloc.h
H_DIR = includes/
C_DIR = srcs/
O_DIR = obj/

C_FILES = malloc.c
C_FILES += free.c
C_FILES += realloc.c
C_FILES += map_first_memblocks.c
C_FILES += init_memblock_list.c
C_FILES += set_tiny.c
C_FILES += set_small.c
C_FILES += set_large.c
C_FILES += assign_block.c
C_FILES += create_new_memblock.c
C_FILES += is_same_ptr.c
C_FILES += putoabase.c
C_FILES += show_alloc_mem.c
C_FILES += print_mem_info.c

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

MAIN = main.c

all:
	make -C $(PRINTF)
	make $(NAME)

$(NAME): $(O_FILES)
	gcc -shared -o $@ $^ libft/libft.a
	@rm -rf $(LINKNAME)
	ln -s $(NAME) $(LINKNAME)

$(O_FILES): $(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2>/dev/null ||echo "" > /dev/null
	$(CC) $(FLAGS) -o $@ -c $<

$(LIBFT):
	@make -C $(PRINTF) all

clean:
	@make -C $(PRINTF) clean
	@rm -rf $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@make -C $(PRINTF) fclean
	@rm -rf $(NAME) $(LINKNAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

.PHONY: re clean fclean malloc all

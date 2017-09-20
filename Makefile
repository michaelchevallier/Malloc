# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 15:49:31 by mchevall          #+#    #+#              #
#    Updated: 2017/09/20 13:10:08 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE:= $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINKNAME = libft_malloc
PRINTF = libft/
PRINTFLIB = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

H_DIR = includes/
C_DIR = srcs/
O_DIR = obj/

C_FILES = malloc.c
C_FILES += free.c
C_FILES += realloc.c
C_FILES += mapFirstMemBlocks.c
C_FILES += initMemBlockList.c
C_FILES += setTiny.c
C_FILES += setSmall.c
C_FILES += setLarge.c
C_FILES += assignBlock.c
C_FILES += createNewMemBlock.c
C_FILES += isSamePtr.c
C_FILES += putoabase.c
C_FILES += show_alloc_mem.c

O_FILES = $(addprefix $(O_DIR),$(C_FILES:.c=.o))

MAIN = main.c

all:
	make -C $(PRINTF)
	make $(NAME)

$(NAME): $(O_FILES)
	ar rc $@ $^
	libtool -static -o $@ $@ libft/libft.a
	ranlib $@
	ln -s $(NAME) $(LINKNAME)

$(O_FILES): $(O_DIR)%.o: $(C_DIR)%.c
	@mkdir $(O_DIR) 2>/dev/null ||echo "" > /dev/null
	$(CC) $(FLAGS) -o $@ -c $<

libft:
	@make -C $(PRINTF) all

clean:
	@make -C $(PRINTF) clean
	@rm -rf $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@make -C $(PRINTF) fclean
	@rm -rf $(NAME) $(LINKNAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

test: $(NAME)
	$(CC) srcs/$(MAIN) $(NAME)

testclean: fclean
	rm -rf a.out

.PHONY: re clean fclean malloc all test testclean

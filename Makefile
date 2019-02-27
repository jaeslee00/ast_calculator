# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 22:35:59 by jaelee            #+#    #+#              #
#    Updated: 2019/02/27 04:01:30 by jaelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ast_calculator
SRCS = ast_calc.c \
		lexer.c \
		grammar.c \
		interpreter.c
INCLUDES = ./includes/ast_calc.h \
			./libft/includes/libft.h
OBJS = $(patsubst %.c,obj/%.o,$(SRCS))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE_FOLDERS = -I./libft/includes -I./includes
LIBRARY_PATH = -L libft

.PHONY: clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) $(LIBRARY_PATH) -lft $(OBJS) -o $@

obj:
	mkdir -p obj

obj/%.o : src/%.c $(INCLUDES) | obj
	$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) -c $< -o $@

libft/libft.a: libft/includes/libft.h
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)
	rm -rf obj

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean
	make all

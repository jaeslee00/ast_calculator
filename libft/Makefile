SRCS = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_atoi.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_islower.c \
		ft_itoa.c \
		ft_putnbr.c \
		ft_putendl.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_splitdel.c \
		ft_readbuff.c \
		list/list_new.c \
		list/list_delone.c \
		list/list_del.c \
		list/list_add.c \
		list/list_pop.c \
		list/list_iter.c \
		list/list_map.c \
		list/list_search.c \
		list/list_rem.c \
		list/list_append.c \
		list/list_rollback.c \
		list/list_length.c \
		list/list_swap.c \
		array/array_init.c \
		array/array_clear.c \
		array/array_pop_back.c \
		array/array_push_back.c \
		array/array_reserve.c \
		array/array_shrink.c \
		queue/queue_init.c \
		queue/queue_pop.c \
		queue/queue_push.c \
		queue/queue_destroy.c \
		tree/tree_recolor.c \
		tree/tree_insert.c \
		tree/tree_rebalance.c \
		tree/tree_rotation.c \
		tree/tree_util.c \
		tree/tree_restructure.c \
		tree/tree_clear.c \
		tree/tree_search.c \
		tree/tree_pre_traverse.c \
		tree/tree_in_traverse.c \
		tree/tree_post_traverse.c \
		ft_max.c \
		ft_min.c \
		ft_sqrt.c \
		ft_itoa_base.c \
		ft_witomb.c \
		get_next_line.c \
		get_next_line_mem.c
OBJS = $(patsubst %.c,obj/%.o,$(SRCS))

CC = gcc
ifndef CFLAGS_WARNINGS
export CFLAGS_WARNINGS = 1
export CFLAGS := $(CFLAGS) -Wall -Wextra -Werror
endif
INCLUDES = includes/libft.h \
		includes/list.h \
		includes/get_next_line.h
INCLUDE_FOLDERS = -Iincludes/
NAME = libft.a

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $@ $^

obj:
	mkdir -p obj
	mkdir -p obj/list
	mkdir -p obj/array
	mkdir -p obj/queue
	mkdir -p obj/tree

obj/%.o: %.c $(INCLUDES) | obj
	gcc $(CFLAGS) $(INCLUDE_FOLDERS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

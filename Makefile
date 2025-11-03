NAME = push_swap

SRCS = src/main.c src/create_stack_A.c src/free_memory.c src/push.c src/reverse_rotate.c src/rotate.c\
src/sort_little_stacks.c src/swap.c src/array.c src/which_sort.c src/sort_chunks.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
INCLUDES = -I$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

checker: $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o checker

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re
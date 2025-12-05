NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRCS        = main.c butterfly_algorithm.c \
              error_handling.c \
              ft_split.c \
              indexing.c \
              ps_atoi.c \
              rotate_reverse.c \
			  sort_ff.c \
              sort.c \
              stack_buliding.c \
              stack_manipulation.c \
              swap_push.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_DIR = get_next_line/
SRCS = main.c \
       pipex.c \
       utils.c \
       heredoc.c \
       pipex_split.c \
       $(GNL_DIR)get_next_line.c \
       $(GNL_DIR)get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
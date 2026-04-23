NAME        = minishell
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I./get_next_line

# Include your readline flags. 
# Note: On 42 Macs, you may need to append -I/usr/local/opt/readline/include to CFLAGS
# and -L/usr/local/opt/readline/lib to RL_FLAGS if it cannot find readline.
RL_FLAGS    = -lreadline

# Your libft archive is in the root directory
LIBFT       = libft.a

SRCS        = main.c \
              lexer.c \
              lexer_utils.c \
              token_expandation.c \
              cmd_list.c \
              init_env.c \
              signal.c \
              builtin.c \
              builtin_exit.c \
              builtin_export.c \
              builtins_cmds.c \
              builtns_env.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(RL_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
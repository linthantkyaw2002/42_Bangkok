NAME        = minishell
CC          = cc

# Detect the operating system
UNAME       := $(shell uname)

# Cross-platform Readline configuration
ifeq ($(UNAME), Darwin)
	# macOS: Find the real GNU Readline installed via Homebrew
	READLINE_DIR = $(shell brew --prefix readline)
	RL_INC       = -I$(READLINE_DIR)/include
	RL_LIB       = -L$(READLINE_DIR)/lib -lreadline
else
	# Linux: Use the standard system Readline
	RL_INC       = 
	RL_LIB       = -lreadline
endif

# Append the Readline includes to your CFLAGS
CFLAGS      = -Wall -Wextra -Werror -I. -I./get_next_line $(RL_INC)

# Your libft archive is in the root directory
LIBFT       = libft.a

SRCS        = main.c \
                builtin_cmds.c \
                builtin_env.c \
                builtin_exit.c \
                builtin_export.c \
                builtin.c \
                cmd_list_utils.c \
                cmd_list.c \
                env_init.c \
                env_utils.c \
                exec_utils.c \
                executor.c \
                handle_redirection.c \
                heredoc.c \
                signal.c \
                token_expand_utils.c \
                token_expand.c \
                token_utils.c \
                tokenize.c \
                get_next_line/get_next_line.c \
                get_next_line/get_next_line_utils.c \

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(RL_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
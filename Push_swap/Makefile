NAME   = push_swap
BONUS  = checker

CC     = cc
CFLAGS = -Wall -Wextra -Werror

RM     = rm -f

# ---------- mandatory push_swap ----------
SRCS = main.c \
       stack_building.c \
       stack_manipulation.c \
       swap_push.c \
       rotate_reverse.c \
       indexing.c \
       sort.c \
       sort_ff.c \
       butterfly_algorithm.c \
       error_handling.c \
       ft_split.c \
       ps_atoi.c

OBJS = $(SRCS:.c=.o)

# ---------- bonus checker ----------
BONUS_SRCS = bonus/checker_main_b.c \
             bonus/checker_exec_b.c \
             bonus/swap_push_bonus.c \
             bonus/rotate_bonus.c \
             bonus/reverse_rotate_bonus.c \
             stack_building.c \
             stack_manipulation.c \
             error_handling.c \
             ft_split.c \
             ps_atoi.c \
             get_next_line/get_next_line_bonus.c \
             get_next_line/get_next_line_utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ---------- rules ----------
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re

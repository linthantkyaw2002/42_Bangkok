# ======================
# Project
# ======================
NAME        = so_long
NAME_BONUS  = so_long_bonus

# ======================
# Compiler
# ======================
CC          = cc
CFLAGS      = -Wall -Wextra -Werror $(MLX_INC)

# ======================
# MLX
# ======================
MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC     = -Iminilibx-linux

# ======================
# Sources
# ======================
# Common files used by both mandatory and bonus
COMMON_SRCS = map.c \
              map_validation.c \
              flood_fill.c \
              map_utils.c \
              draw.c \
              textures.c \
              move.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c

MANDATORY_SRCS = main.c $(COMMON_SRCS)
# Add your future bonus .c files here
BONUS_SRCS = bonus/main_bonus.c \
             bonus/map_validation_bonus.c \
             bonus/draw_bonus.c \
			 bonus/animation_bonus.c \
			 bonus/animation_utils_bonus.c \
			 bonus/handle_keypress_bonus.c \
             $(COMMON_SRCS)

OBJS           = $(MANDATORY_SRCS:.c=.o)
OBJS_BONUS     = $(BONUS_SRCS:.c=.o)

# ======================
# Libraries
# ======================
LIBFT       = libft.a

# ======================
# Rules
# ======================
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Bonus Rule
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
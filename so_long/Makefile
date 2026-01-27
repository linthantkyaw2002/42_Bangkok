# ======================
# Project
# ======================
NAME        = so_long
NAME_BONUS  = so_long_bonus

# ======================
# Compiler & Flags
# ======================
CC          = cc
# Added -Ilibft so you can #include "libft.h" without paths
CFLAGS      = -Wall -Wextra -Werror $(MLX_INC) -ILibft

# ======================
# Paths & Libraries
# ======================
MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC     = -I$(MLX_DIR)

LIBFT_DIR   = Libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ======================
# Sources
# ======================
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
BONUS_SRCS     = bonus/main_bonus.c \
                 bonus/map_validation_bonus.c \
                 bonus/draw_bonus.c \
                 bonus/animation_bonus.c \
                 bonus/animation_utils_bonus.c \
                 bonus/handle_keypress_bonus.c \
                 $(COMMON_SRCS)

OBJS           = $(MANDATORY_SRCS:.c=.o)
OBJS_BONUS     = $(BONUS_SRCS:.c=.o)

# ======================
# Rules
# ======================
all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
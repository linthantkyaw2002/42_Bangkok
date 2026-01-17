# ======================
# Project
# ======================
NAME		= so_long

# ======================
# Compiler
# ======================
CC			= cc
CFLAGS = -Wall -Wextra -Werror $(MLX_INC)


# ======================
# MLX
# ======================
MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_INC = -Iminilibx-linux


# ======================
# Sources
# ======================
SRCS		= main.c \
			  map.c \
			  map_validation.c \
			  flood_fill.c \
			  map_utils.c \
			  draw.c \
			  textures.c \
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

# ======================
# Libraries
# ======================
LIBFT		= libft.a

# ======================
# Rules
# ======================
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

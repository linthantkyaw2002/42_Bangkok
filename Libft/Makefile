NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcat.c \
	ft_strrchr.c ft_bzero.c ft_isdigit.c ft_memmove.c \
	ft_strlcpy.c ft_tolower.c ft_calloc.c ft_isprint.c \
	ft_memset.c ft_strlen.c ft_toupper.c ft_isalnum.c \
	ft_memchr.c ft_strchr.c ft_strncmp.c ft_isalpha.c \
	ft_memcmp.c ft_strdup.c ft_strnstr.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

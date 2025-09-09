NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = ft_printf.c ft_putstr.c ft_putnbr_base.c ft_putnbr_base_uint.c ft_putptr.c

OFILES = $(CFILES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

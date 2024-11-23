CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
CFILES = ft_printf.c ft_printf_helper1.c ft_printf_helper2.c
OBJ = $(CFILES:.c=.o)


all: $(NAME)

# %.o: %.c ft_printf.h
# 	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all
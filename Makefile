NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SB = ./ft_printf.c ./goc.c ./godi.c ./gop.c ./gos.c ./gou.c ./gox.c ./goxx.c ./parse.c ./print.c
OB = $(SB:.c=.o)
LIB = ar -crv
LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c ./libft/*.c -I ./libft
	$(CC) $(CFLAGS) -c $(SB)
	$(LIB) $@ *.o

clean :
	rm -f *.o
	cd ./libft ; make fclean

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re

# NAME = libftprintf.a
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# LIB = ar -crv
# LIBFT = ./libft


# all :
# 	cd $(LIBFT) ; make
# 	ls
# 	$(CC) $(CFLAGS) *.c -lft -L./libft
# 	./a.out
# 	rm a.out

# f :
# 	rm a.out
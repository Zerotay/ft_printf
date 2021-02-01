NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SB = ./ft_printf.c ./goc.c ./godi.c ./gop.c ./gos.c ./gou.c ./gox.c ./goxx.c ./gol.c ./parse.c \
	./print.c ./ito_utils.c ./length_utils.c ./util_for_num1.c ./util_for_num2.c
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

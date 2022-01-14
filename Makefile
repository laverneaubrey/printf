NAME = libftprintf.a

SRC =   ft_printf_utils.c ft_printf.c ft_printf.h

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

DEL = rm

all		: $(NAME)


$(NAME)	: $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	gcc $(FLAG) -c $< -o $@

clean   :
	$(RM)    *.o

fclean	:	clean
	$(RM) $(NAME)

re	    :	fclean all

.PHONY	:	all clean fclean re

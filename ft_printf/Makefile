NAME = libftprintf.a

SRCS = ft_printf.c ft_printnums.c ft_printwords.c

OBJS = $(SRCS:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

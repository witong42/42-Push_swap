NAME = libft.a

SRCS = $(wildcard ft_*.c)

OBJS = $(SRCS:%.c=%.o)

CC = gcc -Wall -Werror -Wextra

RM = rm -f

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

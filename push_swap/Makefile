NAME =		push_swap

SRCS =		srcs/main.c srcs/parsing.c srcs/utils.c srcs/lstd.c \
            srcs/push.c srcs/reverse.c srcs/rotate.c srcs/swap.c \
            srcs/algo.c srcs/algo_utils.c srcs/algo_utils2.c

OBJS =		$(SRCS:%.c=%.o)

# Compile and Flags
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra -I./srcs
LIB =		-L./libft -lft
AR =		ar rcs
RM =		rm -f

all :			$(NAME)

$(NAME) :		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o:%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) -r $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY:		all clean fclean re

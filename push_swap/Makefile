NAME =		push_swap

SRCS =		srcs/main.c srcs/parsing.c srcs/utils.c srcs/lstd.c \
            srcs/push.c srcs/reverse.c srcs/rotate.c srcs/swap.c \
            srcs/algo.c srcs/algo_utils.c srcs/algo_utils2.c

OBJS =		$(SRCS:%.c=%.o)

# Compile and Flags
CC =		gcc -g
CFLAGS =	-Wall -Werror -Wextra -I./srcs -I$(LIBFT)
LIBFT =		./libft
AR =		ar rcs
RM =		rm -f

all :			$(NAME)

$(NAME) :		$(OBJS) $(LIBFT)/libft.a
				$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

$(LIBFT)/libft.a:
				$(MAKE) -C $(LIBFT)

%.o:%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) -r $(OBJS)
				$(MAKE) -C $(LIBFT) clean

fclean: 		clean
				$(RM) $(NAME)
				$(MAKE) -C $(LIBFT) fclean

re: 			fclean all

.PHONY:		all clean fclean re

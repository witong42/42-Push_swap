NAME = fractol

SRCS = fractol.c fractol_utils.c
OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX = minilibx-linux
LIBS = -lmlx -L/usr/lib -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

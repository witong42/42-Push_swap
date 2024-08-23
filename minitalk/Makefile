SRV_NAME = server
SRV_SRCS = server.c
SRV_OBJS = server.o

CLI_NAME = client
CLI_SRCS = client.c
CLI_OBJS = client.o

SRCS = srcs/ft_printf.c srcs/ft_printnums.c srcs/ft_printwords.c
OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(SRV_NAME) $(CLI_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRV_NAME): $(OBJS) $(SRV_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SRV_OBJS) -o $(SRV_NAME)

$(CLI_NAME): $(OBJS) $(CLI_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CLI_OBJS) -o $(CLI_NAME)

clean:
	$(RM) $(OBJS) $(SRV_OBJS) $(CLI_OBJS)

fclean: clean
	$(RM) $(SRV_NAME) $(CLI_NAME)

re: fclean all

.PHONY: all clean fclean re

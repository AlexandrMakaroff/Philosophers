.PHONY = all clean fclean re
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = philo.c \
		init.c \
		threads.c \
		utils.c \
		libft.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJS) : %.o : %.c philo.h

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
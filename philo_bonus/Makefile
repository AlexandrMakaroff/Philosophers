.PHONY = all clean fclean re
NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = philo_bonus.c \
		init.c \
		processes.c \
		utils.c \
		libft.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(OBJS) : %.o : %.c philo_bonus.h

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
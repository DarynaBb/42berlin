NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
			init.c \
			routine.c \
			utils.c \
			monitor.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

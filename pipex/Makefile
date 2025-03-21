# Program name
NAME = pipex
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
		execute.c\
		path_utils.c\
		pipex_utils.c\

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Object files
# automatically generates the names of the object files from the source files
OBJ = $(SRC:.c=.o)

# Header file
HEADER = pipex.h

# Colors for better readability
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Targets
.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft
	@echo "$(GREEN)Program $(NAME) created!$(RESET)"
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)Library $(NAME) removed!$(RESET)"
	
re: fclean all
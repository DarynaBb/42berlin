# Program name
NAME = push_swap
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = algorithm_calculate_rotations.c \
			calc_cost_desc.c\
			calc_cost_asc.c\
			find_target_position.c \
			errors.c \
			push_operations.c \
			push_swap.c \
			reverse_rotate_operations.c \
			rotate_operations.c \
			sorted_func.c \
			swap_operations.c \
			utils.c \
			validate_arg_and_create_stack.c
# Object files
# automatically generates the names of the object files from the source files
OBJ = $(SRC:.c=.o)
# Header file
HEADER = push_swap.h
# Colors for better readability
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
# Targets
.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Program $(NAME) created!$(RESET)"
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Object files removed!$(RESET)"
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Library $(NAME) removed!$(RESET)"
re: fclean all
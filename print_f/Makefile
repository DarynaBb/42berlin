NAME = libftprintf.a

# Compiler and flags
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
print_char.c \
print_hex.c \
print_int.c \
print_pointer.c \
print_str.c \
print_unsigned_int.c \
utils.c

# Object files
# automatically generates the names of the object files from the source files
OBJ = $(SRC:.c=.o)

# Header file
HEADER = ft_printf.h

# Archive command
AR = ar
ARFLAGS = rcs

# Colors for better readability
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Targets
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "$(GREEN)Library $(NAME) created!$(RESET)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Library $(NAME) removed!$(RESET)"

re: fclean all
# Program name
NAME = fractol
# Compiler and flags
CC = cc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Imlx -I$(shell pkg-config --cflags x11)
LDFLAGS = -Lmlx -lmlx -L/opt/homebrew/opt/libx11/lib -L/opt/X11/lib \
          -lX11 -lXext -lm -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR=mlx
LIBMLX_NAME=$(LIBMLX_DIR)/mlx.a
SRC = main.c \
		rendering/julia.c \
		rendering/mandelbrot.c \
		rendering/sierpinski.c \
		rendering/burning_ship.c \
		rendering/render.c \
		utils/color.c \
		utils/complex.c \
		utils/parse_args.c \
		utils/ft_atof.c \
		hooks/keyboard.c \
		hooks/mouse.c \

# Object files
# automatically generates the names of the object files from the source files
OBJ = $(SRC:.c=.o)

HEADER = fractol.h
# LIBS = -Llibft -lft -Lmlx -lmlx -lX11 -lXext -lm -framework OpenGL -framework AppKit

# Colors for better readability
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Targets
.PHONY: all clean fclean re

all: $(LIBFT) $(LIBMLX_NAME) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX_NAME):
	make -C $(LIBMLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX_NAME)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(LIBMLX_DIR) -lmlx
	@echo "$(GREEN)Program $(NAME) created!$(RESET)"
	
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)
	@echo "$(RED)Object files removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)Library $(NAME) removed!$(RESET)"
	
re: fclean all
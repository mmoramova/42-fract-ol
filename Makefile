# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 13:39:03 by mmoramov          #+#    #+#              #
#    Updated: 2023/05/12 20:33:55 by mmoramov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
# NAME_BONUS = checker
HEADER = fractol.h
C_FLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f
SRC_LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft --no-print-directory
SRC_MLX = miniLibX/libmlx.a
MAKE_MLX = make -C miniLibX --no-print-directory
MLX_FLAGS = -framework OpenGL -framework AppKit

# Colors
BLACK = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES = fractol fractol_utils mandelbrot julia
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

all: make_libs make_mlx $(NAME)

make_libs:
	@$(MAKE_LIBFT)

make_mlx:
	@$(MAKE_MLX)

-include ${DEP}

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME):: $(OBJ) ./$(SRC_LIBFT) ./$(SRC_MLX)
	$(CC) $(C_FLAGS) $(^) $(MLX_FLAGS) -o $(NAME)
	@echo "$(BLUE)Everything has been compilated.$(BLACK)"

$(NAME)::
	@echo "$(BLUE)No actions needed.$(BLACK)"

# -include ${DEP_BONUS}

# bonus: make_libs bonusChecker

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJ) $(DEP)
	$(MAKE_LIBFT) clean
	$(MAKE_MLX) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE_LIBFT) fclean
	@echo "$(MAGENTA)Everything has been cleaned.$(BLACK)"

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:18:18 by akocabas          #+#    #+#              #
#    Updated: 2022/06/28 20:45:47 by akocabas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

LIBMLX_DIR = ./minilibx_opengl_20191021/
LIBPRINTF_DIR = ./ft_printf/
LIBMLX = $(addprefix $(LIBMLX_DIR), libmlx.a)
LIBPRINTF =$(addprefix $(LIBPRINTF_DIR), libftprintf.a)

SRC_DIR = ./src/

OBJ_DIR = ./obj/

SRC_FILES = algorithms.c color.c draw.c fract.c init.c keys.c errors.c main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

IMG_SIZE = 600

BSRC_FILES = algorithms_bonus.c color_bonus.c draw_bonus.c drawm_bonus.c \
			errors_bonus.c fract_bonus.c init_bonus.c keys_bonus.c \
			main_bonus.c mousekeys_bonus.c
BOBJ_FILES = $(BSRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

BSRCS = $(addprefix $(SRC_DIR), $(BSRC_FILES))
BOBJS = $(addprefix $(OBJ_DIR), $(BOBJ_FILES))

CC = gcc
MLX_AND_FLAGS = $(LIBMLX) $(LIBPRINTF) -Wall -Wextra -Werror -framework OpenGL -framework AppKit
.PHONY: all clean fclean re bonus

all: $(LIBPRINTF) $(LIBMLX) $(NAME)

$(LIBPRINTF) :
	make -sC $(LIBPRINTF_DIR)

$(LIBMLX) :
	make -sC $(LIBMLX_DIR)

$(NAME): $(LIBMLX) $(LIBPRINTF) $(OBJS)
	@$(CC) $(OBJS) $(MLX_AND_FLAGS) -o $(NAME)
	@echo "fractol compiled."


bonus: $(NAME_BONUS)

${NAME_BONUS} : $(LIBMLX) $(LIBPRINTF) $(BOBJS)
	@$(CC) $(BOBJS) $(MLX_AND_FLAGS) -o $(NAME_BONUS)
	@echo "fractol_bonus compiled."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $^ -I $(LIBPRINTF_DIR) -I $(LIBMLX_DIR) -D IMG_SIZE=$(IMG_SIZE) -o $@

clean:
	@rm -f $(OBJS) $(BOBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean $(NAME)

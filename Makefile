# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:18:18 by akocabas          #+#    #+#              #
#    Updated: 2022/07/25 13:23:28 by akocabas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
OS = MacOS

ifeq ($(OS), Linux)
	LIBMLX_DIR = ./minilibx-linux/
	LIBMLX = $(addprefix $(LIBMLX_DIR), libmlx.a)
	FLAGS = -lmlx -lXext -lX11
else
	LIBMLX_DIR = ./minilibx_opengl_20191021/
	LIBMLX = $(addprefix $(LIBMLX_DIR), libmlx.a)
	FLAGS = -framework OpenGL -framework AppKit
endif

SECURE = $(addprefix $(LIBPRINTF_DIR), ft_printf.h) $(addprefix $(SRC_DIR), fract.h)

BSECURE = $(addprefix $(LIBPRINTF_DIR), ft_printf.h) $(addprefix $(SRC_DIR), fract_bonus.h)

LIBPRINTF_DIR = ./ft_printf/
LIBPRINTF =$(addprefix $(LIBPRINTF_DIR), libftprintf.a)


SRC_DIR = ./src/

OBJ_DIR = ./obj/

SRC_FILES = algorithms.c color.c draw.c fract.c init.c keys.c errors.c main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SIZE = 600

IMG_SIZE = $(addprefix IMG_SIZE=, $(SIZE))

BSRC_FILES = algorithms_bonus.c color_bonus.c draw_bonus.c drawm_bonus.c \
			errors_bonus.c fract_bonus.c init_bonus.c keys_bonus.c \
			main_bonus.c mousekeys_bonus.c
BOBJ_FILES = $(BSRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

BSRCS = $(addprefix $(SRC_DIR), $(BSRC_FILES))
BOBJS = $(addprefix $(OBJ_DIR), $(BOBJ_FILES))

CC = gcc
MLX_AND_FLAGS = -Wall -Wextra -Werror -O3 $(FLAGS) $(LIBMLX) $(LIBPRINTF)

.PHONY: all clean fclean re bonus

all: $(SECURE) $(LIBPRINTF) $(NAME)

$(LIBPRINTF) :
	make -sC $(LIBPRINTF_DIR)

$(LIBMLX) :
	make -sC $(LIBMLX_DIR)

$(NAME): $(LIBMLX) $(LIBPRINTF) $(OBJS)
	@$(CC) $(OBJS) $(MLX_AND_FLAGS) -o $(NAME)
	@echo "fractol compiled."


bonus: $(BSECURE) $(NAME_BONUS)

${NAME_BONUS} : $(LIBMLX) $(LIBPRINTF) $(BOBJS)
	@$(CC) $(BOBJS) $(MLX_AND_FLAGS) -o $(NAME_BONUS) -g
	@echo "fractol_bonus compiled."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $^ -D $(IMG_SIZE) -o $@ -g  -I $(LIBPRINTF_DIR) -I $(LIBMLX_DIR)

clean:
	@rm -f $(OBJS) $(BOBJS)
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBPRINTF_DIR) clean
	@echo Obj files cleaned.

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -sC $(LIBPRINTF_DIR) fclean
	@echo Program deleted.

re: fclean $(NAME)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:18:18 by akocabas          #+#    #+#              #
#    Updated: 2022/06/28 07:27:32 by akocabas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

SRCS = algorithms.c color.c draw.c fract.c init.c keys.c errors.c main.c
OBJS = $(SRCS:.c=.o)

IMG_SIZE = 600

BONUS_SRC = algorithms_bonus.c color_bonus.c draw_bonus.c drawm_bonus.c \
			errors_bonus.c fract_bonus.c init_bonus.c keys_bonus.c \
			main_bonus.c mausekeys_bonus.c
BONUS_OBJS = $(BONUS_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME):  $(OBJS)
	$(CC) $(OBJS) ${CFLAGS} $(MLXFLAGS) minilibx_opengl_20191021/libmlx.a -o $(NAME)

bonus: $(NAME_BONUS)

${NAME_BONUS} : $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(CFLAGS) $(MLXFLAGS) minilibx_opengl_20191021/libmlx.a -o $(NAME_BONUS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS) -D IMG_SIZE=$(IMG_SIZE)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean $(NAME)

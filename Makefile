# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:18:18 by akocabas          #+#    #+#              #
#    Updated: 2022/06/25 13:31:55 by akocabas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = algorithms.c color.c draw.c fract.c init.c keys.c errors.c main.c
OBJS = $(SRCS:.c=.o)

BONUS_SRC =
BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit
MLXFLAGSLINUX = -lmlx -lXext -lX11
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME):  $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGS) minilibx_opengl_20191021/libmlx.a -o $(NAME)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

linux: $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGSLINUX) minilibx_opengl_20191021/libmlx.a -o $(NAME)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	gcc $(NAME)  $(BONUS_OBJS)


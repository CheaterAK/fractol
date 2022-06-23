# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:18:18 by akocabas          #+#    #+#              #
#    Updated: 2022/06/13 14:36:50 by akocabas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT = ./libft/libft.a

SRCS = algorithms.c color.c draw.c fract.c init.c keys.c errors.c main.c
OBJS = $(SRCS:.c=.o)

BONUS_SRC =
BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re bonus

all: $(NAME)

M_Libft:
	make -C libft

$(NAME): M_Libft $(OBJS)
	$(CC) $(OBJS) $(MLXFLAGS) minilibx_macos/libmlx.a $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	gcc $(NAME)  $(BONUS_OBJS)


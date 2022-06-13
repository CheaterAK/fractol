# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 10:18:18 by akocabas          #+#    #+#              #
#    Updated: 2022/06/13 12:21:30 by akocabas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./src

BONUS_SRC_DIR = ./src_bonus

SRCS = algorithms.c color.c draw.c fract.c init.c keys.c
OBJS = $(addprefix $(SRC_DIR)/,$(SRCS:.c=.o))

MAIN_SRC = main.c
MAIN_OBJ = main.o

BONUS =
BONUS_OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -I. -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	ar rcs $(NAME) $(notdir $(OBJS))

%.o: %.c
	$(CC) -c $^ $(CFLAGS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(notdir $(OBJS))

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)


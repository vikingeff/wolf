#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:35 by gleger            #+#    #+#              #
#    Updated: 2014/01/19 18:11:37 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3D

NAMELIB = libw3d.a

HEADERS =	-I headers/ \
			-I /opt/X11/include/X11/

LIBFT = libft/libft.a

LIB = /usr/X11/lib -lmlx -lXext -lX11

SRC =	srcs/file_to_tab.c \
		srcs/list.c \
		srcs/get_next_line.c \
		srcs/mlx.c \
		srcs/draw_walls.c \
		srcs/draw_tool.c \
		srcs/arrows.c \
		srcs/get_walls_pos.c \
		srcs/treat_keys.c \
		srcs/ft_tool.c \
		srcs/ft_strtool.c \
		srcs/ft_strother.c \
		srcs/ft_strsplit.c \
		srcs/main.c

OBJ = $(SRC:.c=.o)

CC = gcc -g -Wall -Wextra -Werror -O3

%.o: %.c ./headers/get_next_line.h ./headers/wolf3d.h
	@echo "\033[1;36;m[Compiling $<]\t\033[0m: " | tr -d '\n'
	$(CC) -c $< $(HEADERS)
	@mv *.o ./srcs

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	@ar rc $(NAMELIB) $(OBJ)
	@ranlib $(NAMELIB)
	$(CC) -o $@ $(OBJ) $(NAMELIB) -L$(LIB)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAMELIB)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAMELIB)
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
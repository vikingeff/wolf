#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 14:36:35 by po-conno          #+#    #+#              #
#    Updated: 2014/01/19 18:11:37 by po-conno         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3D

NAMELIB = libw3d.a

HEADERS =	-I headers/ \
			-I libft/includes/ \
			-I /opt/X11/include/X11/

LIBFT = libft/libft.a

LIB = /usr/X11/lib -lmlx -lXext -lX11

SRC =	srcs/file_to_tab.c \
		srcs/list.c \
		srcs/get_next_line.c \
		srcs/mlx.c \
		srcs/draw_bg.c \
		srcs/draw_walls.c \
		srcs/set_cam.c \
		srcs/arrows.c \
		srcs/make_blank.c \
		srcs/get_walls_pos.c \
		srcs/treat_keys.c \
		main.c

OBJ = $(SRC:.c=.o)

CC = gcc -g -Wall -Wextra -Werror

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rc $(NAMELIB) $(OBJ)
	ranlib $(NAMELIB)
	$(CC) -o $@ $(OBJ) $(NAMELIB) $(LIBFT) -L$(LIB)

clean:
	make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	@rm -f $(NAMELIB)
	@rm -f $(NAME)

re: fclean all

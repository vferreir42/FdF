# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:20:58 by vferreir          #+#    #+#              #
#    Updated: 2017/12/12 14:50:36 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_INC = ./libft/includes/

CC	=	gcc

RM	=	/bin/rm -f

SRC	=	main.c				\
		map.c \
		event.c \
		event2.c \
		mlx.c \
		math.c \
		iso.c \
		parallele.c \
		get_next_line.c \
		parcing.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

LIB = libft/libft.a

NAME	=	fdf

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[33;32m=== Compilation\t\t\tDONE===\033[0m"

clean:
	make -C libft/ clean
	$(RM) $(OBJ)
	@echo "\033[33;31m=== Object\t\t\tDELETED===\033[0m"

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)
	@echo "\033[33;31m=== Binary\t\t\tDELETED===\033[0m"

re: fclean all

.PHONY: all clean fclean re lib

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuliia <myuliia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 13:49:14 by myuliia           #+#    #+#              #
#    Updated: 2019/06/05 12:50:26 by myuliia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = ./src/main.c \
	  ./src/vector_op.c \
	  ./src/vector_op_2.c \
	  ./src/ft_error.c \
	  ./src/key_hooks.c \
	  ./src/draw.c \
	  ./src/titles.c \
	  ./src/parser.c \
	  ./src/parser_add.c \
	  ./src/t_calculation.c \
	  ./src/intersect.c \
	  ./src/bright.c \
	  ./src/init_light.c \
	  ./src/draw_helper.c \

OBJ = $(SRC: .c=.o)

HEADER = ./include/rtv1.h

FLAGS = -lmlx -framework OpenGL -framework AppKit -flto -Ofast -pipe -Wall -Wextra -Werror

all:     $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
		@echo "\x1b[33mCompiation succes!"
%.o: %.c $(HEADER) libft/
		@gcc -c -g -o $@ $<

clean:
		@rm -f *.o

fclean:	clean
		@rm -f $(NAME)
re: fclean all


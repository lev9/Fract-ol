# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:30:56 by laskolin          #+#    #+#              #
#    Updated: 2020/03/09 10:17:54 by laskolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBMLX2 = ./lib/libmlx2

LIBFT = ./lib/libft

SRC = main.c preparations.c draw_utils.c threader.c threader2.c threader3.c \
	fractols.c zoom.c mouse.c highlight.c keys.c keys2.c styles.c styles2.c \
	colors.c colors2.c buddhabrot.c buddhavalues.c help.c

OBJ = $(subst .c,.o,$(SRC))

MLXFLAGS = -L$(LIBMLX2) -lmlx -I /usr/X11/include \
        -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

LIBFTFLAGS = -L$(LIBFT) -lft

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBFT)/
	make -C $(LIBMLX2)/
	gcc $(FLAGS) -I libft/ -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFTFLAGS) $(MLXFLAGS)

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIBFT)/

fclean: clean
	make fclean -C $(LIBFT)/
	/bin/rm -f $(NAME)

re: fclean all

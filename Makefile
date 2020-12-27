# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laskolin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:30:56 by laskolin          #+#    #+#              #
#    Updated: 2020/03/09 10:17:54 by laskolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c preparations.c draw_utils.c threader.c threader2.c threader3.c \
	fractols.c zoom.c mouse.c highlight.c keys.c keys2.c styles.c styles2.c \
	colors.c colors2.c buddhabrot.c buddhavalues.c help.c

OBJ = $(subst .c,.o,$(SRC))

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I libft/ -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -L /usr/local/lib -lmlx -I /usr/X11/include \
	-L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit -L./libft -lft

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all

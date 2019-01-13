# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:24:16 by agottlie          #+#    #+#              #
#    Updated: 2018/12/29 12:28:36 by agottlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC2 = map_creator.c fillit.c other.c list_tmples.c validate_ttr.c

OBJ2 = *.o

INC = libft

all: $(NAME)

$(NAME):
	make -C libft fclean && make -C libft
	gcc $(FLAGS) -c $(SRC2) -I $(INC)
	gcc $(FLAGS) -Llibft -lft -I$(INC) -o $(NAME) main.c $(OBJ2)

clean:
	/bin/rm -f $(OBJ2)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f fillit.a
	make -C libft fclean

re: fclean all

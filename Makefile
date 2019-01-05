# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:24:16 by agottlie          #+#    #+#              #
#    Updated: 2019/01/05 09:17:05 by agottlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

FLAGS = -Wall -Wextra -Werror -g

SRC = libft/ft_*.c

OBJ = ft_*.o

INC = libft/libft.h

all: $(NAME)

$(NAME): fclean
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

f:
	@gcc $(FLAGS) -L. $(NAME) main.c map_creator.c fillit.c other.c list_tmples.c validate_ttr.c -o fillit
	@/bin/rm -f $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all

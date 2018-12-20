# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:24:16 by agottlie          #+#    #+#              #
#    Updated: 2018/12/19 17:52:57 by agottlie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

FLAGS = -Wall -Wextra

SRC = libft/ft_*.c

OBJ = ft_*.o

INC = libft/libft.h

all: $(NAME)

$(NAME): fclean
	@gcc $(FLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc $(FLAGS) -L. $(NAME) fillit.c
	@/bin/rm -f $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all

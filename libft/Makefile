# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 08:54:37 by yharwyn-          #+#    #+#              #
#    Updated: 2018/12/17 15:17:56 by yharwyn-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_*.c get_next_line.c

INCLUDES = libft.h

OBJECTS = ft_*.o get_next_line.o

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	ar rc  $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f *.o
	/bin/rm -f $(NAME)

re: fclean $(NAME)
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykirigay <ykirigay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 08:01:38 by ykirigay          #+#    #+#              #
#    Updated: 2020/02/29 08:01:38 by ykirigay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=*.c ft_printf/*.c array_int/*.c

OBJECTS=*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

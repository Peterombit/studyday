# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykirigay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 18:56:49 by ykirigay          #+#    #+#              #
#    Updated: 2020/02/10 18:56:52 by ykirigay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= srcs/checks.c \
			  srcs/error.c \
			  srcs/fillit.c \
			  srcs/init_game.c \
			  srcs/solver.c \
			  srcs/store.c
OBJS		= $(subst .c,.o,$(subst srcs/,,$(SRCS)))

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -I includes/ -I libft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: clean fclean all re

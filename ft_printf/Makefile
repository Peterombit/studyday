# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 17:48:34 by vdelsie           #+#    #+#              #
#    Updated: 2019/12/14 19:56:42 by vdelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = /bin/rm -f

LFT = libft/
LFT_INC = -I ./libft/includes/

NAME = libftprintf.a
SRCS_DIR = ./
FILES = ft_printf parse_prespecifiers parse_specifier int_handlers\
uint_handlers double_handlers str_char_handlers special_handlers\
hard_double_handlers printf_gen_utils printf_double_utils printf_utf_utils\
printf_int_utils
CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, %.o, $(FILES))
INCLUDES = ./includes
CFLAGS = -Wall -Wextra -Werror -O2
LIBS = -L $(LFT)
LIBFILENAMES = ft_memset.o ft_bzero.o ft_strlen.o ft_isdigit.o ft_isascii.o ft_strequ.o
LIBFILES = $(addprefix $(LFT), $(LIBFILENAMES))

.PHONY: all clean fclean re

all : lib $(NAME)

lib:
	make -C $(LFT)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@  -I $(INCLUDES) $(LFT_INC)

$(NAME) : $(OFILES)
	ar rc $(NAME) $(OFILES) $(LIBFILES)
	ranlib $(NAME)

clean :
	make -C $(LFT) clean
	$(RM) $(OFILES)
	$(RM) $(LFT_OFILES)

fclean : clean
	make -C $(LFT) fclean
	$(RM) $(NAME)

re : fclean all

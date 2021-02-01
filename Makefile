# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vazra <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 10:42:11 by vazra             #+#    #+#              #
#    Updated: 2021/02/01 12:58:36 by vazra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_printf.c ft_convert_int.c ft_convert_char.c ft_convert_hexa.c ft_convert_pointer.c ft_itoa_pf.c ft_utils.c

SRCSBONUS =

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJSBONUS) 

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus make

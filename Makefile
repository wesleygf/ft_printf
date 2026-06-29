# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/29 11:39:24 by wgolbert          #+#    #+#              #
#    Updated: 2026/06/29 12:11:24 by wgolbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = ft_puthexa \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re	
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamori <velvelhype@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 03:20:19 by kamori            #+#    #+#              #
#    Updated: 2021/11/23 04:47:58 by kamori           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME)

bonus: $(NAME)

server: $(OBJS_SERVER)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_SERVER) libft/libft.a -o server

client: $(OBJS_CLIENT)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS_CLIENT) libft/libft.a -o client

clean:
	make clean -C libft
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
	make re -C libft
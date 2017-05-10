# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 06:20:47 by jwebb             #+#    #+#              #
#    Updated: 2017/05/10 06:45:24 by jwebb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

FILES = ft_printf.c set_args.c print_args.c
SRCS = $(addprefix srcs/,$(FILES))
OBJS = $(addprefix build/,$(FILES:.c=.o))

LIBS = libft/libft.a

INCLUDES = -I includes -I libft
CFLAGS = -Wall -Wextra -Werror

CC = gcc
AR = ar rc

all: $(NAME)

$(LIBS):
	make -C libft

$(NAME): $(OBJS) | $(LIBS)
	$(AR) $(NAME) $(OBJS)

build:
	mkdir build

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf build
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

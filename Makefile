# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 06:20:47 by jwebb             #+#    #+#              #
#    Updated: 2017/06/21 12:46:32 by jwebb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = add_chars.c add_xprefix.c apply_mods.c ft_addchar.c ft_addstr.c\
		ft_addwstr.c ft_printf.c ft_printf_arg.c ft_putascii.c get_args.c\
		set_args.c
SRCS = $(addprefix srcs/,$(FILES))
OBJS = $(addprefix build/,$(FILES:.c=.o))
HEAD = includes/ft_printf.h libft/libft.h

LIBS = libft/libft.a
LIBOBJS = libft/ft_*.o

INCLUDES = -I includes -I libft
CFLAGS = -Wall -Wextra -Werror

CC = gcc
AR = ar rc

all: $(NAME)

$(LIBS):
	@make -C libft

$(NAME): $(OBJS) $(HEAD)
	@echo "Creating $(NAME)..."
	@$(AR) $(NAME) $(OBJS) $(LIBOBJS)

build: $(LIBS)
	@echo "Creating objects for $(NAME)..."
	@mkdir build

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Removing objects for $(NAME)..."
	@rm -rf build
	@make clean -C libft

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

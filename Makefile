# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebb <jwebb@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 06:20:47 by jwebb             #+#    #+#              #
#    Updated: 2017/06/21 20:41:36 by jwebb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c set_args.c ft_isalpha.c ft_strcmp.c\
		ft_putchar.c ft_putstr.c ft_putwchar.c ft_putwstr.c ft_strcpy.c\
		ft_putnbr.c ft_putlong.c ft_putunbr.c ft_putulong.c ft_putshort.c\
		ft_putsize_t.c ft_putlonglong.c ft_putulonglong.c ft_putintmax_t.c\
		ft_putuintmax_t.c ft_putascii.c ft_isdigit.c\
		ft_atoi.c ft_itoh.c ft_uctoa_base.c ft_ustoa_base.c ft_uitoa_base.c\
		ft_ultoa_base.c ft_toupper.c ft_printf_arg.c get_args.c add_xprefix.c\
		ft_strlen.c ft_nbrlen.c ft_unbrlen.c apply_mods.c add_chars.c\
		ft_memalloc.c ft_memset.c ft_wctomb.c ft_putwchar.c ft_putwstr.c\
		ft_bzero.c ft_strmethod.c ft_addchar.c ft_addstr.c ft_addwstr.c\
		ft_getwchar.c ft_ltoa.c ft_memcpy.c ft_memdel.c ft_realloc.c ft_strcat.c
SRCS = $(addprefix srcs/,$(FILES))
OBJS = $(addprefix build/,$(FILES:.c=.o))
HEAD = includes/ft_printf.h includes/libft.h

LIBS = libft/libft.a

INCLUDES = -I includes -I libft
CFLAGS = -Wall -Wextra -Werror

CC = gcc
AR = ar rc

all: $(NAME)

$(LIBS):
	make -C libft

$(NAME): $(OBJS) $(HEAD)
	@echo "Creating $(NAME)..."
	@$(AR) $(NAME) $(OBJS)

build:
	@echo "Creating objects..."
	@mkdir build

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Deleting objects..."
	@rm -rf build

fclean: clean
	@echo "Deleting $(NAME)..."
	@rm -rf $(NAME)

re: fclean all

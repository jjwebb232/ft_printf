# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebb <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 15:36:58 by jwebb             #+#    #+#              #
#    Updated: 2017/06/21 12:31:29 by jwebb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FILES	= ft_atoi.c ft_bzero.c ft_itoa.c ft_nbrlen.c ft_unbrlen.c ft_itoh.c\
		  ft_uitoa_base.c ft_ultoa_base.c ft_imtoa_base.c ft_uimtoa_base.c\
		  ft_sqrt.c ft_swap.c ft_wordcount.c ft_wordlen.c\
		  ft_is_prime.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c\
		  ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		  ft_memdel.c ft_memmove.c ft_memrcpy.c ft_memset.c ft_realloc.c\
		  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putunbr.c\
		  ft_putlong.c ft_putulong.c\
		  ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		  ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		  ft_strstr.c ft_strsub.c ft_strtrim.c \
		  ft_tolower.c ft_toupper.c get_next_line.c ft_cvrtnbr.c \
		  ft_putpixel.c ft_fillpixel.c\
		  ft_matbzero.c ft_matidentity.c ft_matmultiply.c ft_matrotate.c \
		  ft_matscale.c ft_matxpoint.c \
		  ft_buildline.c ft_printline.c\
		  ft_getwchar.c ft_ltoa.c ft_wctomb.c

SRCS	= $(FILES)
OBJS	= $(FILES:.c=.o)

CC = gcc
CFLAGS ?= -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	@echo "Building $(NAME)"
	@$(CC) $(CFLAGS) -c $^ $(SRCS)
	@ar rc $(NAME) $(OBJS)

clean:
	@echo "Removing objects for $(NAME)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)

re: fclean all

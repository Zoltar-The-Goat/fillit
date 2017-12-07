# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 06:01:16 by ananelli          #+#    #+#              #
#    Updated: 2017/11/07 00:21:38 by ananelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c

SRC = ft_isprint.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c \
	  ft_toupper.c ft_itoa.c ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c \
	  ft_memalloc.c	ft_putchar_fd.c	ft_strclr.c ft_strlcat.c ft_strnstr.c \
	  ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c ft_strrchr.c \
	  ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c \
	  ft_strsplit.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c \
	  ft_strmapi.c ft_strstr.c ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c \
	  ft_strdup.c ft_strncat.c ft_strsub.c ft_isascii.c ft_memdel.c \
	  ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c ft_isdigit.c \
	  ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c ft_tolower.c \
	  ft_isspace.c ft_alt_strsub.c ft_wordcount.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c

OBJ = *.o

all	:	$(NAME)

$(NAME)	:
			gcc $(FLAG) $(OPTION) $(SRC)
			ar rcs $(NAME) $(OBJ)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

run		:	$(NAME) clean
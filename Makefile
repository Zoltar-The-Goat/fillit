# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 00:31:13 by Zoltar            #+#    #+#              #
#    Updated: 2017/11/12 01:07:17 by Zoltar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ./lib
SRC = ./src

all : $(NAME)

$(NAME) :
			$(CC) $(FLAGS) -o $(NAME)

clean :

fclean :

re :
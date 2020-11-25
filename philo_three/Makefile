# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 19:33:23 by jvaquer           #+#    #+#              #
#    Updated: 2020/11/25 19:28:34 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -pthread
endif

NAME = philo_three

SRCS = 	actions.c 				\
		check_vars.c			\
		display.c				\
		../utils/errors.c		\
		init_philo.c			\
		monitoring.c			\
		parsing.c				\
		philo_three.c			\
		../utils/time.c			\

LIB =	../lib/ft_atoi.c  		\
		../lib/ft_strcmp.c		\
		../lib/ft_strcpy.c		\
		../lib/ft_strdup.c		\
		../lib/ft_strjoind.c	\
		../lib/ft_strlen.c		\
		../lib/ft_strndup.c		\
		../lib/ft_uilen.c		\
		../lib/ft_uitoa.c		\

OBJ = $(SRCS:.c=.o)

OBJ_LIB = $(LIB:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	$(OBJ) $(OBJ_LIB)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_LIB)
clean : 
			rm -rf $(OBJ) $(OBJ_LIB)

fclean :	clean
			rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean

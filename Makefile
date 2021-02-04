# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard@student.42.fr <ericard>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:59:01 by ericard@stu       #+#    #+#              #
#    Updated: 2021/02/04 16:44:26 by ericard@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cub3d.c \
			srcs/tab_init.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/parsing.c \

INCLUDE	=	-I include/

NAME	=	Cub3D

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -rf

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra

.c.o:		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
			@printf "\e[1A\e[0K"

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard@student.42.fr <ericard>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:59:01 by ericard@stu       #+#    #+#              #
#    Updated: 2021/02/22 13:48:41 by ericard@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cub3d.c \
			tab_init.c \
			get_next_line.c \
			get_next_line_utils.c \
			parsing.c \
			parsing_colors_res.c \
			parsing_map.c \
			map_is_valid.c \
			parsing_textures.c \
			errors.c \
			
NAME	=	cub3D

OBJ_DIR =	objs
SRC_DIR =	srcs
INCLUDE	=	include

OBJ	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

RM		=	rm -rf

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra #-g -fsanitize=address

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
				@printf "\e[1A\e[0K"

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
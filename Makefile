# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard@student.42.fr <ericard>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:59:01 by ericard@stu       #+#    #+#              #
#    Updated: 2021/03/03 14:12:07 by ericard@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	cub3d.c \
			tab_init.c \
			get_next_line.c \
			get_next_line_utils.c \
			parsing.c \
			parsing_res.c \
			parsing_colors.c \
			parsing_map.c \
			map_is_valid.c \
			parsing_textures.c \
			errors.c \
			close.c \
			start_mlx.c \
			key_hook.c \
			mlx_utils.c \
			
NAME	=	cub3D

OBJ_DIR =	objs
SRC_DIR =	srcs
INCLUDE	=	include
MLX_DIR =	minilibx-linux

OBJ	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

RM		=	rm -rf

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra #-g -fsanitize=address

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			

all:		$(NAME)

$(NAME):	$(OBJ)
			@cd minilibx-linux && make
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -I $(INCLUDE) -I $(MLX_DIR) -c $< -o $@
				@printf "\e[1A\e[0K"

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			@cd minilibx-linux && make clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
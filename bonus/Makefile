# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 21:10:08 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/07 01:24:55 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME:=fdf

SRC_DIR:=srcs/
SRCS:=main_bonus.c \
	draw_fdf_bonus.c \
	draw_info_bonus.c \
	get_next_line.c \
	hooks_1_bonus.c \
	hooks_2_bonus.c \
	init_file.c \
	init_map.c \
	init_transform_bonus.c \
	projection_bonus.c \
	update_bonus.c \
	utils1.c \
	utils2.c

INC_DIR:=incs/

FT:=ft
FT_DIR:=../libft

MLX:=mlx
MLX_DIR:=../minilibx

CC:=cc
CFLAGS:=-Wall -Wextra -Werror

RM:=rm
RMFLAGS:=-f

$(NAME) : $(addprefix $(SRC_DIR), $(SRCS))
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) \
		-I $(FT_DIR) -L $(FT_DIR) -l $(FT) \
		-I $(MLX_DIR) -L $(MLX_DIR) -l $(MLX) -framework OpenGL -framework AppKit

.PHONY : clean re

clean :
	$(RM) $(RMFLAGS) $(NAME)

re : clean $(NAME)
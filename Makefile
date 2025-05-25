# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahwang <ahwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 14:16:20 by ahwang            #+#    #+#              #
#    Updated: 2025/05/24 00:10:49 by ahwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)

INCS_DIR = ./incs
SRCS_DIR = ./srcs

FILES = main \
	check_args \
	draw_fractol \
	mandelbrot \
	julia \
	mlx_utils \
	utils

INCS_BONUS_DIR = ./incs_bous
SRCS_BONUS_DIR = ./srcs_bonus

FILES_BONUS = main_bonus \
	check_args_bonus \
	draw_fractol_bonus \
	mandelbrot_bonus \
	julia_bonus \
	burning_ship_bonus \
	mlx_utils_bonus \
	utils_bonus

SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(SRCS_DIR)/, $(addsuffix .o, $(FILES)))

SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, $(addsuffix .c, $(FILES_BONUS)))
OBJS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, $(addsuffix .o, $(FILES_BONUS)))

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS_DIR)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

$(MLX):
	chmod 775 $(MLX_DIR)/configure
	make -C $(MLX_DIR)

bonus: $(LIBFT_NAME) $(NAME_BONUS)

$(NAME_BONUS): $(MLX) $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_BONUS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all, bonus, clean, fclean, re

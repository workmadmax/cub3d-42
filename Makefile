# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 14:21:12 by madmax42          #+#    #+#              #
#    Updated: 2023/06/14 16:22:26 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = leila
INCLUDES   = -I./includes -I./libft -I./mlx_linux

CC         = gcc
CFLAGS     = -Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS   = -fPIE -lXext -lX11 -lm

LIBFT_PATH = ./libft
MLX_PATH   = ./mlx_linux

RM         = rm -rf

SRCS       = test.c

VPATH      = ./srcs/

OBJS_DIR   = objects
OBJS       = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a $(NAME)

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a
	$(CC) $(CFLAGS) $(MLXFLAGS) -L$(MLX_PATH) -L$(LIBFT_PATH) -lmlx -lft $(OBJS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	$(RM) $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
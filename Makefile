# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 14:21:12 by madmax42          #+#    #+#              #
#    Updated: 2023/06/18 15:53:52 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						=	so_long

LIBFT_PATH					=	./libft
MLX_PATH					=	./minilibx-linux

LIBFT						=	$(LIBFT_PATH)/include/libft.a
MLX_LINUX					=	$(MLX_PATH)/libmlx_Linux.a

INCLUDES					=	-I./includes -I$(LIBFT_PATH) -I$(MLX_PATH)

SRCS						=	test.c \
									handle_file.c \
									validate_map.c \
									init_data.c \
									libft.c \
									
								

VPATH						=	./srcs/ \
									./srcs/handle_map/ \
									./srcs/utils/ \
									

OBJS_DIR					=	objects
OBJS						=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

CC							=	gcc
CFLAGS						=	-Wall -Wextra -Werror -g3
MLX_FLAGS_LINUX				=	-lXext -lX11 -lm -lz

$(OBJS_DIR)/%.o:			%.c
								@mkdir -p $(OBJS_DIR)
								$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: 						$(NAME)

$(NAME):					$(OBJS) $(LIBFT) $(MLX_LINUX)
								$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) \
								-lft -L$(MLX_PATH) $(MLX_FLAGS_LINUX) -o $(NAME)

$(LIBFT):
								$(MAKE) -C $(LIBFT_PATH)

$(MLX_LINUX):
								$(MAKE) -C $(MLX_PATH)

clean:
								$(MAKE) -C $(LIBFT_PATH) clean
								$(MAKE) -C $(MLX_PATH) clean
								$(RM) $(OBJS_DIR)

fclean:						clean
								$(MAKE) -C $(LIBFT_PATH) fclean
								$(RM) $(NAME)

re:							fclean all

.PHONY:						all clean fclean re

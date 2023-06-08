# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 14:21:12 by madmax42          #+#    #+#              #
#    Updated: 2023/06/08 11:07:18 by madmax42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						=	leila

CC							=	gcc
CFLAGS						=	-Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS					=	-lmlx_linux -X11 -lXext -lm

LIB_PATHS					=	./libft/libft.a ./mlx_linux/libmlx_linux.a

RM							=	rm -rf

SRCS						=	main.c

#VPATH						= 	./srcs/

OBJS_DIR					=	objects
OBJS						=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))


$(OBJS_DIR)/%.o:			%.c
							@mkdir -p $(OBJS_DIR)
							$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all:						$(LIB_PATHS) $(NAME)

$(LIB_PATHS):
							$(MAKE) -C ./libft
							$(MAKE) -C ./mlx_linux

$(NAME):					$(OBJS)
							$(CC) $(CFLAGS) $(MLXFLAGS) $(LIB_PATHS) $(OBJS) -o $(NAME)

clean:
							$(MAKE) -C ./libft clean
							$(MAKE) -C ./mlx_linux clean
							$(RM) *.o

fclean:						clean
							make clean -C ./libft
							make clean -C ./mlx_linux
							$(RM) $(NAME)
							
re:							fclean all

.PHONY:						all clean fclean re
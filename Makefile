# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:49:49 by hyuncpar          #+#    #+#              #
#    Updated: 2022/10/28 18:21:26 by hyuncpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc -g -fsanitize=address
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

SRCS		= main.c read_map.c check_map.c key_event.c print_error.c memory_free.c utils.c \
				setting.c
GNL_SRCS	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
MLX_DIR		= ./mlx/

MLX_FLAGS	= -L ./mlx -lmlx -framework OpenGL -framework Appkit

OBJS		= $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

all	: $(NAME)

clean :
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean :
	clean
	$(RM) $(NAME)

re	: clean all

PHONY	:	all clean fclean re bonus
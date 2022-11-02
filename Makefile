# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:49:49 by hyuncpar          #+#    #+#              #
#    Updated: 2022/11/02 22:04:37 by hyuncpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BNAME		= so_long_bonus

CC			= cc -g -fsanitize=address
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

SRCS		= main.c read_map.c check_map.c key_event.c print_error.c memory_free.c utils.c \
				setting.c processing_move.c game_exit.c ft_itoa.c
BSRCS		= ./bonus/main.c ./bonus/read_map.c ./bonus/key_event.c ./bonus/print_error.c \
				./bonus/memory_free.c ./bonus/utils.c ./bonus/setting.c	./bonus/processing_move.c \
				./bonus/game_exit.c ./bonus/ft_itoa.c ./bonus/check_map.c ./bonus/enemy_list.c \
				./bonus/move_enemy.c

GNL_SRCS	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
MLX_DIR		= ./mlx/

MLX_FLAGS	= -L ./mlx -lmlx -framework OpenGL -framework Appkit

OBJS		= $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o) $(GNL_SRCS:.c=.o)
.c.o :
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

$(BNAME) : $(BOBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(BNAME) $(BOBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

bonus : $(BNAME)

clean :
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME) $(BNAME)

re	: clean all

PHONY	:	all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: picatrai <picatrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 09:25:45 by picatrai          #+#    #+#              #
#    Updated: 2023/12/29 15:22:36 by picatrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/ft_split.c src/so_long.c src/map_valide.c src/utilitaires.c src/add_border.c \
src/ft_print_map.c src/ft_move.c src/ft_item.c src/ft_enemy_move.c src/check_path.c \
src/free.c src/ft_enemy_move_utils.c src/check_path_utils.c src/so_long_suite.c \
src/ft_no_nl_mid.c
OBJ = ${SRC:.c=.o}
MLX_FLAGS = -L minilibx-linux -lmlx -lXext -lX11
INCLUDES = -I minilibx-linux -I include

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $< ${INCLUDES}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${MLX_FLAGS}

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all
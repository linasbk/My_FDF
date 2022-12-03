# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsabik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 15:06:24 by lsabik            #+#    #+#              #
#    Updated: 2022/11/25 15:06:28 by lsabik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
NAME := fdf
SRC_NAME =	main_COPY.c Bresenhams_COPY.c ft_split.c get_next_line.c utils.c ft_atoi.c read_map.c colors.c
OBJ = $(SRC_NAME:.c=.o)

all: ${NAME}
$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -Imlx -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

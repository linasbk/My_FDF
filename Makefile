CC := cc
NAME := fdf
SRC_NAME =	main.c DDA.c ft_split.c get_next_line.c utils.c\
				ft_atoi.c read_map.c colors.c draw.c init.c fdf_control.c utilis_fdf.c
OBJ = $(SRC_NAME:.c=.o)

all: ${NAME}
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -ofast -framework AppKit -o $(NAME)

%.o: %.c fdf.h
	$(CC) -fno-signed-zeros -mtune=intel -Ofast -march=native -fno-trapping-math -Wall -Wextra -Werror  -Imlx -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

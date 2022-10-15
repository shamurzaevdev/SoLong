NAME = so_long

LIB_NAME = so_long.a

CC = gcc

FLAG = -Wall -Wextra -Werror -g

SRC =	get_next_line_utils.c \
		get_next_line.c \
		moving_down.c \
		moving_right.c \
		moving_left.c \
		moving_up.c \
		so_long.c \
		utils.c \
		moving_ingame.c \

AR = ar -rcs

OBJ = $(addprefix src/,$(SRC:.c=.o))

src/%.o: src/%.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

all:$(NAME)

$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a src/$(LIB_NAME)
	$(AR) src/$(LIB_NAME) $(OBJ)
	$(CC) -lmlx -framework OpenGL -framework AppKit src/$(LIB_NAME) -o $(NAME) $?

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean	
	rm -f $(NAME) src/$(LIB_NAME)

re: fclean clean all
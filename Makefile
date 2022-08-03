NAME = so_long
 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	check_parse.c			\
		draw_map.c	\
		move_player.c	\
		move_player2.c	\
		parse_map.c	\
		putimage.c	\
		render_next_frame.c	\
		so_long.c

OBJS = $(SRCS:.c=.o)

all: ${NAME} ${OBJS}

$(NAME):
	@make bonus -C ./libft
	@make -C ./ft_printf
	@make -C ./mlx
	$(CC) $(CFLAGS)  $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft ft_printf/libftprintf.a  -o so_long

clean:
	make -C ./libft clean
	make -C ./ft_printf clean
	make -C ./mlx clean
	rm -f  $(OBJS)

fclean: clean
	make -C ./libft fclean
	make -C ./ft_printf fclean
	rm -f $(NAME)


re: fclean all

.PHONY: re clean fclean all
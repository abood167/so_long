NAME = so_long
 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
MLX = mlx/libmlx.dylib

SRCS = 	check_parse.c			\
		draw_map.c	\
		move_player.c	\
		move_player2.c	\
		parse_map.c	\
		putimage.c	\
		render_next_frame.c	\
		so_long.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft ft_printf/libftprintf.a  -o so_long

$(LIBFT):
	@make bonus -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(MLX): 
	@make -C ./mlx
	cp $(MLX) .

clean:
	make -C ./libft clean
	make -C ./ft_printf clean
	make -C ./mlx clean
	rm -f  $(OBJS)

fclean: clean
	make -C ./libft fclean
	make -C ./ft_printf fclean
	rm -f $(NAME) libmlx.dylib

bonus: $(NAME)


re: fclean all

.PHONY: re clean fclean all
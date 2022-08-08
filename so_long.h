/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:42:57 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/08 02:11:02 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include"./mlx/mlx.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define FLOOR "./graond.xpm"
# define WALL "./wall.xpm"
# define PLAYER "./character.xpm"
# define PLAYER2 "./character2.xpm"
# define COIN1 "./D1.xpm"
# define COIN2 "./D2.xpm"
# define COIN3 "./D3.xpm"
# define EXIT "./DOOR.xpm"

typedef struct s_game
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	t_list	*map;
	int		coins;
	int		steps;
	void	*plyer;
	void	*plyer2;
	void	*exit;
	void	*floor;
	void	*wall;
	void	*col[4];
	int		face;
	int		count_collectibles;
}t_game;

int		count_exits(t_list *map);
int		y_pos(t_list *map);
int		x_pos(t_list *map);
int		count_collectibles(t_list *map);
int		count_players(t_list *map);
int		is_rectangular(t_list *map);
int		check_chars(t_list *map);
int		check_walls(t_list *map);
int		finel_check(t_list *map);
int		move_right(t_game *game);
int		move_right_helper(t_game *game, char *line, int i, int line_num);
void	defin_image(t_game	*game, int size);
int		ft_close2(t_game	*game);

int		move_up(t_game *game);
int		move_up_helper(t_list **nodes, t_game *game, int i, int cnt);
int		move_left(t_game *game);
int		move_left_helper(t_game *game, char *line, int i, int line_num);
int		move_down(t_game *game);
int		mvoe_down_helper(t_list *node, t_game *game, int i, int cnt);
void	put_wall(t_list *map, char c, int x, int y);
void	Put_player(t_list *map, char c, int x, int y);
void	draw_map(t_game *game);
void	draw_image(t_game *game, void *img, int x, int y);
void	choose_block(t_game *game, char c, int x, int y);
t_list	*read_map(char *str);
int		key_hook(int keycode, t_game *game);
int		ft_close(t_game	*game);
void	ft_error(void);
int		render_next_frame(t_game	*game);
int		move_up_helper2(t_list **nodes, t_game *game, int i);
int		move_down_helper2(t_list *node, t_game *game, int i);

#endif
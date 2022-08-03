/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:35:21 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/01 20:06:54 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_lstclear (&game->map, free);
	mlx_destroy_image(game->mlx, game->img);
	exit(1);
}

int	ft_close2(t_game	*game)
{
	ft_printf("Moves = %d\n", game->steps);
	ft_lstclear (&game->map, free);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	game.steps = 0;
	game.face = 0;
	game.mlx = mlx_init();
	game.map = read_map (av[1]);
	finel_check(game.map);
	game.mlx_win = mlx_new_window(game.mlx,
			ft_strlen((char *)game.map->content) * 64,
			ft_lstsize(game.map) * 64, "so_long");
	game.img = mlx_new_image(game.mlx, ft_strlen((char *)game.map->content)
			* 64, ft_strlen((char *)game.map->content) * 64);
	draw_map(&game);
	mlx_hook(game.mlx_win, 17, 0, ft_close, &game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	ft_lstclear (&game.map, free);
	mlx_destroy_window(game.mlx, game.mlx_win);
	mlx_destroy_image(game.mlx, game.img);
}

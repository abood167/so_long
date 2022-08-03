/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:41:08 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/01 19:21:11 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_game *game, void *img, int x, int y)
{
	int		size;
	char	*stps;

	size = 64;
	stps = ft_itoa(game->steps);
	x = x * (size - 1);
	y = y * (size - 1);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 30, 40, 0x000000FF, "Moves");
	mlx_string_put(game->mlx, game->mlx_win, 30, 60, 0x000000FF, stps);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x, y);
	free (stps);
}

void	choose_block(t_game *game, char c, int x, int y)
{
	if (c == '0')
		draw_image(game, game->floor, x, y);
	if (c == '1')
	{
		draw_image(game, game->floor, x, y);
		draw_image(game, game->wall, x, y);
	}
	if (c == 'C')
	{
		draw_image(game, game->floor, x, y);
		draw_image(game, game->col[3], x, y);
	}
	if (c == 'E')
		draw_image(game, game->exit, x, y);
	if (c == 'P')
	{
		draw_image(game, game->floor, x, y);
		draw_image(game, game->plyer, x, y);
	}
}

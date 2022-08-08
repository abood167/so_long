/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:02:22 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/08 01:21:00 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_new_coin(t_game *game, int x, int y, int index)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->floor, x * 63, y * 63);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->col[index], x * 63, y * 63);
}

void	switch_coin(t_game *game)
{
	static int	index;
	char		*line;
	int			cnt;
	int			z;
	t_list		*map;

	map = game->map;
	if (index >= 4)
		index = 0;
	cnt = 0;
	while (map != NULL)
	{
		z = 0;
		line = map->content;
		while (line[z] != '\0')
		{
			if (line[z] == 'C')
				draw_new_coin(game, z, cnt, index);
			++z;
		}
		cnt++;
		map = map->next;
	}
	index++;
}

int	render_next_frame(t_game	*game)
{
	static int	cnt;

	cnt++;
	if (cnt == 5000)
	{
		switch_coin(game);
		cnt = 0;
	}
	return (0);
}

int	move_up_helper2(t_list **nodes, t_game *game, int i)
{
	if (((char *)(nodes[0]->content))[i] == 'E')
	{
		if (game->coins == 0)
			ft_close2(game);
		return (0);
	}
	if (((char *)(nodes[0]->content))[i] == '1')
	{
		game->steps--;
		return (0);
	}
	return (1);
}

int	move_down_helper2(t_list *node, t_game *game, int i)
{
	if (((char *)(node->next->content))[i] == 'E')
	{
		if (game->coins == 0)
			ft_close2(game);
		else
			return (0);
	}
	if (((char *)(node->next->content))[i] == '1')
	{
		game->steps--;
		return (0);
	}
	return (1);
}

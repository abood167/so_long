/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:43:16 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/08 02:28:36 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_close(game);
	game->coins = count_collectibles(game->map);
	if (keycode == 2 || keycode == 124)
	{
		if (move_right(game) == 0)
			return (0);
	}
	if (keycode == 13 || keycode == 126)
	{		
		if (move_up(game) == 0)
			return (0);
	}
	if (keycode == 0 || keycode == 123)
	{
		if (move_left(game) == 0)
			return (0);
	}
	if (keycode == 1 || keycode == 125)
	{
		if (move_down(game) == 0)
			return (0);
	}
	return (0);
}

int	move_right(t_game *game)
{
	char	*line;
	t_list	*node;
	int		cnt;
	int		i;

	node = game->map;
	cnt = 0;
	while (node != NULL)
	{
		line = node->content;
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == 'P')
			{
				if (move_right_helper(game, node->content, i, cnt) == 0)
					return (0);
			}
			i++;
		}
		cnt++;
		node = node->next;
	}
	return (1);
}

int	move_right_helper(t_game *game, char *line, int i, int line_num)
{
	game->steps++;
	if (line[i + 1] == 'C')
		game->coins = game->coins - 1;
	if (line[i + 1] == 'E' && game->coins == 0)
		ft_close2(game);
	if (line[i + 1] == 'E')
		return (0);
	if (line[i + 1] == '1')
	{
		draw_image(game, game->floor, i, line_num);
		draw_image(game, game->plyer2, i, line_num);
		game->steps--;
		return (0);
	}
	line[i] = '0';
	line[i + 1] = 'P';
	{
		draw_image(game, game->floor, i + 1, line_num);
		draw_image(game, game->plyer2, i + 1, line_num);
		game->face = 2;
		draw_image(game, game->floor, i, line_num);
	}
	ft_printf(KGRN"Moves = %d\n"KNRM, game->steps);
	return (0);
}

int	move_up(t_game *game)
{
	char	*line;
	t_list	*nodes[2];
	int		cnt;
	int		i;

	nodes[0] = NULL;
	nodes[1] = game->map;
	cnt = 0;
	while (nodes[1] != NULL)
	{
		line = nodes[1]->content;
		i = 0;
		while (line[i])
		{
			if (line[i] == 'P')
				if (move_up_helper(nodes, game, i, cnt) == 0)
					return (0);
			i++;
		}
		cnt++;
		nodes[0] = nodes[1];
		nodes[1] = nodes[1]->next;
	}
	return (0);
}

int	move_up_helper(t_list **nodes, t_game *game, int i, int cnt)
{
	game->steps++;
	if (((char *)(nodes[0]->content))[i] == 'C')
		game->coins = game->coins - 1;
	if (move_up_helper2(nodes, game, i) == 0)
		return (0);
	if (nodes[0] == NULL)
		return (0);
	((char *)(nodes[1]->content))[i] = '0';
	((char *)(nodes[0]->content))[i] = 'P';
	draw_image(game, game->floor, i, cnt - 1);
	if (game->face == 2)
		draw_image(game, game->plyer2, i, cnt - 1);
	else
		draw_image(game, game->plyer, i, cnt - 1);
	draw_image(game, game->floor, i, cnt);
	ft_printf(KBLU"Moves = %d\n"KNRM, game->steps);
	return (0);
}

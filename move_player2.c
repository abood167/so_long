/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:59:30 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/08 02:27:16 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_game *game)
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
				if (move_left_helper(game, node->content, i, cnt) == 0)
					return (0);
			}
			i++;
		}
		cnt++;
		node = node->next;
	}
	return (1);
}

int	move_left_helper(t_game *game, char *line, int i, int line_num)
{
	game->steps++;
	if (line[i - 1] == 'C')
		game->coins = game->coins - 1;
	if (line[i - 1] == 'E' && game->coins == 0)
		ft_close2(game);
	if (line[i - 1] == 'E')
		return (0);
	if (line[i - 1] == '1')
	{
		draw_image(game, game->floor, i, line_num);
		draw_image(game, game->plyer, i, line_num);
		game->steps--;
		return (0);
	}
	line[i] = '0';
	line[i - 1] = 'P';
	draw_image(game, game->floor, i - 1, line_num);
	draw_image(game, game->plyer, i - 1, line_num);
	game->face = 1;
	draw_image(game, game->floor, i, line_num);
	ft_printf(KCYN"Moves = %d\n"KNRM, game->steps);
	return (0);
}

int	move_down(t_game *game)
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
		while (line[i])
		{
			if (line[i] == 'P')
			{
				if (mvoe_down_helper(node, game, i, cnt) == 0)
					return (0);
			}
			i++;
		}
		cnt++;
		node = node->next;
	}
	return (1);
}

int	mvoe_down_helper(t_list *node, t_game *game, int i, int cnt)
{
	game->steps++;
	if (((char *)(node->next->content))[i] == 'C')
		game->coins = game->coins - 1;
	if (move_down_helper2(node, game, i) == 0)
		return (0);
	if (node->next == NULL)
		return (0);
	((char *)(node->content))[i] = '0';
	((char *)(node->next->content))[i] = 'P';
	draw_image(game, game->floor, i, cnt + 1);
	if (game->face == 1)
		draw_image(game, game->plyer, i, cnt + 1);
	else
		draw_image(game, game->plyer2, i, cnt + 1);
	draw_image(game, game->floor, i, cnt);
	ft_printf(KMAG"Moves = %d\n"KNRM, game->steps);
	return (0);
}

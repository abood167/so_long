/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:28:00 by abin-saa          #+#    #+#             */
/*   Updated: 2022/08/08 03:25:28 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*read_map(char *str)
{
	int		fd;
	t_list	*list;
	char	*line;
	t_list	*el;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error ();
	list = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		ft_error ();
	if (ft_strlen(line) == 1 && *line == '\n')
		ft_error();
	line = ft_strtrim(line, "\n");
	while (line != NULL)
	{
		line = ft_strtrim(line, "\n");
		el = ft_lstnew(line);
		if (el == NULL)
			exit(1);
		ft_lstadd_back(&list, el);
		line = get_next_line(fd);
	}
	return (list);
}

void	draw_map(t_game *game)
{
	char	*line;
	int		col;
	int		size;
	int		row;
	t_list	*node;

	node = game->map;
	row = 0;
	size = 0;
	defin_image (game, size);
	while (node != NULL)
	{
		col = 0;
		line = node->content;
		while (line[col] != '\0')
		{
			choose_block(game, line[col], col, row);
			col++;
		}
		row++;
		node = node->next;
	}
}

void	defin_image(t_game	*game, int size)
{
	game->plyer = mlx_xpm_file_to_image(game->mlx, PLAYER, &size, &size);
	game->plyer2 = mlx_xpm_file_to_image(game->mlx, PLAYER2, &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
	game->col[0] = mlx_xpm_file_to_image(game->mlx, COIN1, &size, &size);
	game->col[1] = mlx_xpm_file_to_image(game->mlx, COIN3, &size, &size);
	game->col[2] = mlx_xpm_file_to_image(game->mlx, COIN2, &size, &size);
	game->col[3] = mlx_xpm_file_to_image(game->mlx, COIN3, &size, &size);
}

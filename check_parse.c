/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:09:22 by abin-saa          #+#    #+#             */
/*   Updated: 2022/07/30 08:01:06 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_list	*map)
{
	int			i;
	char		*line1;
	char		*line_last;

	i = -1;
	line1 = map->content;
	while (line1[++i] != '\0')
		if (line1[i] != '1')
			return (0);
	line_last = ft_lstlast(map)->content;
	i = -1;
	while (line_last[++i] != '\0')
		if (line_last[i] != '1')
			return (0);
	while (map != NULL)
	{
		i = 0;
		line1 = map->content;
		if (line1[0] != '1')
			return (0);
		if (line1[ft_strlen(line1) - 1] != '1')
			return (0);
		map = map->next;
	}
	return (1);
}

int	finel_check(t_list	*map)
{
	if (count_players(map) != 1)
		ft_error();
	if (count_exits(map) == 0)
		ft_error();
	if (count_collectibles(map) == 0)
		ft_error();
	if (check_walls(map) == 0)
		ft_error();
	if (check_chars(map) == 0)
		ft_error();
	if (is_rectangular(map) == 0)
		ft_error();
	return (1);
}

void	ft_error(void)
{
	ft_putstr ("invalid Map");
	exit (1);
}

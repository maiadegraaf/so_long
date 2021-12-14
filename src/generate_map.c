/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 09:21:37 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/14 16:11:59 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_invalid_walls(t_map *map, int x, int y)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		if ((tmp->x == 0 && tmp->content != '1')
			|| (tmp->x == x - 1 && tmp->content != '1'))
			return (1);
		if ((tmp->y == 0 && tmp->content != '1')
			|| (tmp->y == y - 1 && tmp->content != '1'))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_invalid_c(t_map	*map, char c)
{
	int		i;
	t_map	*tmp;

	tmp = map;
	i = 0;
	while (tmp)
	{
		if (tmp->content == c)
			i++;
		tmp = tmp->next;
	}
	if (!i)
		return (1);
	return (0);
}

int	check_invalid(t_map	*map, int x, int y)
{
	if (check_invalid_c(map, 'P'))
		return (1);
	if (check_invalid_c(map, 'C'))
		return (1);
	if (check_invalid_c(map, 'E'))
		return (1);
	if (check_invalid_walls(map, x, y))
		return (1);
	return (0);
}

int	convert_map(char *init, t_map **map, int y)
{
	int		x;
	t_map	*node;

	x = 0;
	while (init[x] && init[x] != '\n')
	{
		node = ft_mapnew(x, y, init[x]);
		if (!node)
		{
			ft_mapclear(map);
			return (0);
		}
		ft_mapadd_back(map, node);
		x++;
	}
	return (x - 1);
}

int	generate_map(char *input, t_tools *tools)
{
	char	*init;
	int		fd;

	tools->map_h = 0;
	fd = open(input, O_RDONLY);
	init = get_next_line(fd);
	tools->map_w = ft_strlen_c(init, '\n');
	tools->map = NULL;
	while (init)
	{
		if (convert_map(init, &tools->map, tools->map_h) != tools->map_w - 1)
		{
			clear_map(tools->map);
			return (1);
		}
		tools->map_h++;
		free(init);
		init = get_next_line(fd);
	}
	free(init);
	if (check_invalid(tools->map, tools->map_w, tools->map_h))
	{
		clear_map(tools->map);
		return (1);
	}
	return (0);
}

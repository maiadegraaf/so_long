/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_err_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 12:28:58 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:36:10 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

int	check_map_c(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (tmp)
	{
		if (tmp->content != '1' && tmp->content != '0'
			&& tmp->content != 'P' && tmp->content != 'E'
			&& tmp->content != 'C')
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_invalid(t_map	*map, int x, int y)
{
	int		err;

	err = 0;
	if (check_map_c(map))
		err = 2;
	else if (check_invalid_c(map, 'P'))
		err = 4;
	else if (check_invalid_c(map, 'C'))
		err = 5;
	else if (check_invalid_c(map, 'E'))
		err = 6;
	else if (check_invalid_walls(map, x, y))
		err = 7;
	if (err != 0)
	{
		ft_mapclear(&map);
		ft_error(err);
	}
	return (0);
}

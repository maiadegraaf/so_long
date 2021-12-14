/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:28:19 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/14 09:35:04 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_rand(int weight)
{
	return ((rand() % 100) < weight);
}

int	determine_empty_space(t_map *map)
{
	int		e;
	t_map	*tmp;

	tmp = map;
	e = 0;
	while (tmp)
	{
		if (tmp->content == '0')
			e++;
		tmp = tmp->next;
	}
	return (e);
}

int	assign_new_number(int x_y)
{
	if (ft_rand(50))
		x_y++;
	else
		x_y--;
	return (x_y);
}

int	check_start_ok(t_tools *tools, int x, int y)
{
	if (x >= tools->map_w - 1)
		return (1);
	else if (y >= tools->map_h - 1)
		return (1);
	else if (x <= 1)
		return (1);
	else if (y <= 1)
		return (1);
	if (x == tools->player.x)
		return (1);
	else if (y == tools->player.y)
		return (1);
	else if (check_pos(tools->walls, tools, x, y))
		return (1);
	return (0);
}

void	check_fringe(int *x_y, int max)
{
	if (*x_y >= max)
		(*x_y)--;
	else if (*x_y <= 1)
		(*x_y)++;
}

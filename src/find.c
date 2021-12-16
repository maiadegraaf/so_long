/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 10:21:49 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/16 13:40:29 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_walls(t_tools **tools)
{
	t_map	*tmp;
	t_map	*walls;
	t_map	*node;

	walls = NULL;
	tmp = (*tools)->map;
	while (tmp)
	{
		if (tmp->content == '1')
		{
			node = ft_mapnew(tmp->x, tmp->y, tmp->content);
			if (!node)
			{
				ft_mapclear(&walls);
				return ;
			}
			ft_mapadd_back(&walls, node);
		}
		tmp = tmp->next;
	}
	(*tools)->walls = walls;
}

void	find_exits(t_tools **tools)
{
	t_map	*tmp;
	t_map	*exit;
	t_map	*node;

	exit = NULL;
	tmp = (*tools)->map;
	while (tmp)
	{
		if (tmp->content == 'E')
		{
			node = ft_mapnew(tmp->x, tmp->y, tmp->content);
			if (!node)
			{
				ft_mapclear(&exit);
				return ;
			}
			ft_mapadd_back(&exit, node);
		}
		tmp = tmp->next;
	}
	(*tools)->exit = exit;
}

int	find_start(t_tools **tools)
{
	t_map	*tmp;

	tmp = (*tools)->map;
	while (tmp)
	{
		if (tmp->content == 'P')
		{
			(*tools)->player.x = tmp->x;
			(*tools)->player.y = tmp->y;
			break ;
		}
		tmp = tmp->next;
	}
	(*tools)->player.new_x = (*tools)->player.x;
	(*tools)->player.new_y = (*tools)->player.y;
	return (1);
}

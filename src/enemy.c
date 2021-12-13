/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:18:48 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/13 15:47:53 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*assign_pos(t_player *enemy)
{
	t_map	*pos;
	t_map	*node;

	pos = NULL;
	node = ft_mapnew(enemy->x + 1, enemy->y, 'y');
	if (node)
		ft_mapadd_back(&pos, node);
	node = ft_mapnew(enemy->x - 1, enemy->y, 'y');
	if (node)
		ft_mapadd_back(&pos, node);
	node = ft_mapnew(enemy->x, enemy->y + 1, 'y');
	if (node)
		ft_mapadd_back(&pos, node);
	node = ft_mapnew(enemy->x, enemy->y - 1, 'y');
	if (node)
		ft_mapadd_back(&pos, node);
	return (pos);
}

void	determine_x_y(t_player *enemy, t_map *pos, int i)
{
	int	j;
	int	r;

	j = 4 - i;
	r = rand() % j;
	j = 0;
	while (j < r)
	{
		pos = pos->next;
		j++;
	}
	enemy->new_x = pos->x;
	enemy->new_y = pos->y;
}

void	find_new_pos_enemy(t_tools *tools, t_player *enemy)
{
	t_map	*pos;
	t_map	*start;
	t_map	*prev;
	int		i;

	pos = assign_pos(enemy);
	start = pos;
	i = 0;
	while (pos)
	{
		if (check_pos(tools->walls, tools, pos->x, pos->y))
		{
			pos->content = 'n';
			ft_mapdelone(&start, 'n');
			i++;
		}
		if (pos)
		{
			prev = pos;
			pos = pos->next;
		}
	}
	if (i == 4)
		return ;
	determine_x_y(enemy, start, i);
}

int	check_pos(t_map	*walls, t_tools *tools, int x, int y)
{
	t_map			*tmp;

	tmp = walls;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (1);
		tmp = tmp->next;
	}
	if (x == tools->e_x)
		return (1);
	if (y == tools->e_y)
		return (1);
	return (0);
}

int	check_enemy(t_player *enemy, t_tools *tools)
{
	if (enemy->new_x == enemy->x && enemy->new_y == enemy->y)
		find_new_pos_enemy(tools, enemy);
	if (enemy->mv_pxl < SPRITE_SIZE)
	{
		enemy->diff_x = enemy->new_x - enemy->x;
		enemy->diff_y = enemy->new_y - enemy->y;
		enemy->mv_pxl += 2;
		enemy->mv_x = enemy->mv_pxl * enemy->diff_x;
		enemy->mv_y = enemy->mv_pxl * enemy->diff_y;
		if (enemy->mv_pxl % 4 == 0)
			enemy->cur_img++;
		if (enemy->cur_img == 4)
			enemy->cur_img = 0;
	}
	else if (enemy->mv_pxl >= SPRITE_SIZE)
		clear_player_info(enemy);
	return (1);
}

//&& tools->i % 50 == 0
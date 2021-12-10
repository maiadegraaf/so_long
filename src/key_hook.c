/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 10:36:52 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/10 13:47:14 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_tools *tools, t_player *player)
{
	t_map	*tmp;
	int		x;
	int		y;

	x = player->x + player->diff_x;
	y = player->y + player->diff_y;
	tmp = tools->walls;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (0);
		tmp = tmp->next;
	}
	player->new_x = x;
	player->new_y = y;
	return (1);
}

int	check_bugs(t_tools *tools)
{
	t_bugs	*tmp;

	tmp = tools->bugs;
	while (tmp)
	{
		if (tmp->x == tools->player.new_x && tmp->y == tools->player.new_y
			&& tmp->content == 'C')
		{
			tmp->content = '0';
			tools->yum = 100;
			change_coordinate(tools);
			tools->num_bugs--;
			return (1);
		}	
		tmp = tmp->next;
	}
	return (0);
}

int	check_params(t_tools *tools)
{
	if (!check_walls(tools, &tools->player))
	{
		tools->player.diff_x = 0;
		tools->player.diff_y = 0;
		return (0);
	}
	if (check_bugs(tools))
		return (1);
	if (tools->e_x == tools->player.new_x
		&& tools->e_y == tools->player.new_y
		&& tools->num_bugs == 0)
	{
		printf("so long\n");
		mlx_destroy_window(tools->vars->mlx, tools->vars->win);
		exit(0);
	}
	return (1);
}

int	check_wasd(int keycode, t_tools *tools)
{
	if (!(tools->player.diff_y == 0 && tools->player.diff_x == 0))
		return (0);
	if (keycode == KEY_W || keycode == ARROW_UP)
	{
		tools->player.img = tools->tarantulas.up;
		tools->player.diff_y = -1;
	}
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
	{
		tools->player.img = tools->tarantulas.down;
		tools->player.diff_y = 1;
	}
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
	{
		tools->player.img = tools->tarantulas.left;
		tools->player.diff_x = -1;
	}
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
	{
		tools->player.img = tools->tarantulas.right;
		tools->player.diff_x = 1;
	}
	check_params(tools);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate_enemy_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:22:28 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:36:10 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_enemy_frames(t_tools *tools)
{
	tools->enemy[0] = convert_xpm("img/enemy/0.xpm", *tools->vars);
	tools->enemy[1] = convert_xpm("img/enemy/1.xpm", *tools->vars);
	tools->enemy[2] = convert_xpm("img/enemy/0.xpm", *tools->vars);
	tools->enemy[3] = convert_xpm("img/enemy/2.xpm", *tools->vars);
}

void	initiate_enemy(t_tools *tools, t_player *enemy)
{
	enemy->img = tools->enemy;
	enemy->cur_img = 0;
	enemy->mv_pxl = 0;
	enemy->mv_x = 0;
	enemy->mv_y = 0;
	enemy->diff_x = 0;
	enemy->diff_y = 0;
}

int	determine_num_enemys(int empty)
{
	int	i;
	int	num_enemys;

	num_enemys = 0;
	i = 0;
	while (i < empty)
	{
		num_enemys += ft_rand(5);
		i++;
	}
	return (num_enemys);
}

void	create_enemy_list(t_tools *tools)
{
	t_player		enemy;
	int				i;
	t_enemy_list	*tmp;

	i = tools->num_enemys;
	while (i > 0)
	{
		tmp = ft_enemy_listnew(&enemy);
		if (!tmp)
		{
			free(tmp);
			ft_enemy_listclear(&tools->enemys);
			tools->num_enemys = 0;
			return ;
		}
		initiate_enemy(tools, &tmp->enemy);
		if (find_start_pos_enemy(tools, &tmp->enemy))
		{
			tools->num_enemys--;
			free(tmp);
		}
		else
			ft_enemy_listadd_back(&tools->enemys, tmp);
		i--;
	}
}

int	find_start_pos_enemy(t_tools *tools, t_player *enemy)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = rand() % tools->map_w - 1;
	y = rand() % tools->map_h - 1;
	while (check_start_ok(tools, x, y))
	{
		check_fringe(&x, tools->map_w - 1);
		check_fringe(&y, tools->map_h - 1);
		if (ft_rand(50))
			x = assign_new_number(x);
		else
			y = assign_new_number(y);
		i++;
		if (i == 40)
			return (1);
	}
	enemy->x = x;
	enemy->y = y;
	enemy->new_x = x;
	enemy->new_y = y;
	return (0);
}

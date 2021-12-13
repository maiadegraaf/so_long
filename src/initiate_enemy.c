#include "../includes/so_long.h"

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

int	create_enemy_list(t_tools *tools)
{
	t_player		enemy;
	int				i;
	t_enemy_list	*tmp;
	t_enemy_list	*tmp_list;

	tools->num_enemys = determine_num_enemys(tools->empty);
	if (tools->num_enemys == 0)
		return (0);
	i = tools->num_enemys;
	tmp_list = NULL;
	while (i > 0)
	{
		tmp = ft_enemy_listnew(&enemy);
		if (!tmp)
		{
			free(tmp);
			ft_enemy_listclear(&tmp_list);
			return (0);
		}
		initiate_enemy(tools, &tmp->enemy);
		find_start_pos_enemy(tools, &tmp->enemy);
		ft_enemy_listadd_back(&tmp_list, tmp);
		i--;
	}
	tools->enemys = tmp_list;
	return (1);
}

void	find_start_pos_enemy(t_tools *tools, t_player *enemy)
{
	int	x;
	int	y;

	x = rand() % tools->map_w - 1;
	y = rand() % tools->map_h - 1;
	while (check_pos(tools->walls, tools, x, y))
	{
		if (x >= tools->map_w - 1)
			x--;
		else if (y >= tools->map_h - 1)
			y--;
		else if (x <= 1)
			x++;
		else if (y <= 1)
			y++;
		if (ft_rand(50))
			x++;
		else
			y--;
	}
	enemy->x = x;
	enemy->y = y;
	enemy->new_x = x;
	enemy->new_y = y;
}

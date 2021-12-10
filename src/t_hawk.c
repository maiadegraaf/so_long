#include "../includes/so_long.h"

int	**assign_pos(t_player *t_hawk)
{
	int	**pos;
	int	i;

	i = 0;
	pos = ft_calloc(4, sizeof(int *));
	while (i < 4)
		pos[i++] = ft_calloc(2, sizeof(int));
	pos[0][0] = t_hawk->x + 1;
	pos[0][1] = 0;
	pos[1][0] = t_hawk->x - 1;
	pos[1][1] = 0;
	pos[2][0] = 0;
	pos[2][1] = t_hawk->y + 1;
	pos[3][0] = 0;
	pos[3][1] = t_hawk->y - 1;
	return (pos);
}

int	check_not_all_neg(int **pos)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (pos[i][0] == -1)
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

void	find_new_pos_t_hawk(t_tools *tools, t_player *t_hawk)
{
	int	**pos;
	int	i;
	int	r;

	pos = assign_pos(t_hawk);
	i = 0;
	while (i < 4)
	{
		if (check_pos(tools->walls, tools->t_hawks, pos[i][0], pos[i][1]))
		{
			pos[i][0] = - 1;
			pos[i][0] = - 1;
		}
		i++;
	}
	if (check_not_all_neg(pos))
		return ;
	r = rand() % 4;
	while (pos[r][0] > - 1)
	{
		r = rand() % 4;
	}
	t_hawk->new_x = pos[r][0];
	t_hawk->new_y = pos[r][0];
	free_arr((char **)pos);
}

int	check_pos(t_map	*walls, t_t_hawk_list *l_t_hawk, int x, int y)
{
	t_map			*tmp;
	t_t_hawk_list	*th_tmp;
	
	tmp = walls;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (1);
		tmp = tmp->next;
	}
	th_tmp = l_t_hawk;
	while (th_tmp)
	{
		if (th_tmp->t_hawk->x == x && th_tmp->t_hawk->y == y)
			return (1);
		th_tmp = th_tmp->next;
	}
	return (0);
}

int	check_t_hawk(t_player *t_hawk, t_tools *tools)
{
	if (t_hawk->new_x == t_hawk->x && t_hawk->new_y == t_hawk->y)
		find_new_pos_t_hawk(tools, t_hawk);
	if (t_hawk->mv_pxl < SPRITE_SIZE)
	{
		t_hawk->diff_x = t_hawk->new_x - t_hawk->x;
		t_hawk->diff_y = t_hawk->new_y - t_hawk->y;
		t_hawk->mv_pxl += 2;
		t_hawk->mv_x = t_hawk->mv_pxl * t_hawk->diff_x;
		t_hawk->mv_y = t_hawk->mv_pxl * t_hawk->diff_y;
		if (t_hawk->mv_pxl % 4 == 0)
			t_hawk->cur_img++;
		if (t_hawk->cur_img == 4)
			t_hawk->cur_img = 0;
	}
	else if (t_hawk->mv_pxl >= SPRITE_SIZE)
	{
		t_hawk->mv_pxl = 0;
		t_hawk->mv_x = 0;
		t_hawk->mv_y = 0;
		t_hawk->x = t_hawk->new_x;
		t_hawk->y = t_hawk->new_y;
		t_hawk->diff_x = 0;
		t_hawk->diff_y = 0;
	}
	return (1);
}

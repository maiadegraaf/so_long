#include "../includes/so_long.h"

void	initiate_t_hawk(t_tools *tools, t_player *t_hawk)
{
	t_img_t_hawk	frame;
	frame.img[0] = convert_xpm("img/t_hawk/0.xpm", *tools->vars);
	frame.img[1] = convert_xpm("img/t_hawk/1.xpm", *tools->vars);
	frame.img[2] = convert_xpm("img/t_hawk/0.xpm", *tools->vars);
	frame.img[3] = convert_xpm("img/t_hawk/2.xpm", *tools->vars);
	t_hawk->img = frame.img;
	t_hawk->cur_img = 0;
	t_hawk->mv_pxl = 0;
	t_hawk->mv_x = 0;
	t_hawk->mv_y = 0;
	t_hawk->diff_x = 0;
	t_hawk->diff_y = 0;
}

int	determine_num_t_hawks(int empty)
{
	int	i;
	int	num_t_hawks;

	num_t_hawks = 0;
	i = 0;
	while (i < empty)
	{
		num_t_hawks += ft_rand(5);
		i++;
	}
	return (num_t_hawks);
}

int	create_t_hawk_list(t_tools *tools)
{
	t_player		t_hawk;
	int				i;
	t_t_hawk_list	*tmp;
	t_t_hawk_list	*tmp_list;

	tools->num_t_hawks = determine_num_t_hawks(tools->empty);
	printf("num of hawks = %d\n", tools->num_t_hawks);
	if (tools->num_t_hawks == 0)
		return (0);
	i = tools->num_t_hawks;
	tmp_list = NULL;
	while (i > 0)
	{
		tmp = ft_t_hawk_listnew(&t_hawk);
		if (!tmp)
		{
			free(tmp);
			ft_t_hawk_listclear(&tmp_list);
			return (0);
		}
		initiate_t_hawk(tools, &tmp->t_hawk);
		find_start_pos_t_hawk(tools, &tmp->t_hawk);
		ft_t_hawk_listadd_back(&tmp_list, tmp);
		printf("%d, %d\n", tmp_list->t_hawk.x, tmp_list->t_hawk.y);
		i--;
	}
	tools->t_hawks = tmp_list;
	printf("%d, %d\n", tools->t_hawks->t_hawk.x, tools->t_hawks->t_hawk.y);
	return (1);
}

void	find_start_pos_t_hawk(t_tools *tools, t_player *t_hawk)
{
	int	x;
	int	y;

	x = rand() % tools->map_w;
	y = rand() % tools->map_h;
	while (!check_pos(tools->walls, tools->t_hawks, x, y))
	{
		if (x < tools->map_w)
			x++;
		else if(y < tools->map_h)
			y++;
		else if (x > 0)
			x--;
		else if (y > 0)
			y--;
	}
	t_hawk->x = x;
	t_hawk->y = y;
	t_hawk->new_x = x;
	t_hawk->new_y = y;
}
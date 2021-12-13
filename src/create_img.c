#include "../includes/so_long.h"

void	draw_map(t_tools *tools)
{
	t_map	*tmp;
	t_bugs	*b_tmp;

	tmp = tools->map;
	b_tmp = tools->bugs;
	while (tmp)
	{
		canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &tools->sand);
		if (tmp->content == '1')
			canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &tools->cactus);
		if (tmp->content == 'E')
			canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &tools->hovel);
		if (tmp->content == 'C')
		{
			while (b_tmp)
			{
				if (b_tmp->x == tmp->x && b_tmp->y == tmp->y)
					break ;
				b_tmp = b_tmp->next;
			}
			canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &b_tmp->bug);
		}
		tmp = tmp->next;
	}
	canvas_p_pixel_put(&tools->canvas, tools->player.x, tools->player.y, &tools->player);
	draw_enemys(tools, tools->enemys);
}

#define SHUT(x) (void)x;

void	draw_enemys(t_tools *tools, t_enemy_list *enemy)
{
	t_enemy_list	*tmp;

	tmp = enemy;
	while (tmp)
	{
		canvas_p_pixel_put(&tools->canvas, tmp->enemy.x, tmp->enemy.y, &tmp->enemy);
		tmp = tmp->next;
	}
}

t_data	convert_xpm(char *rel_p, t_vars vars)
{
	t_data	img;
	int		img_w;
	int		img_h;

	img.img = mlx_xpm_file_to_image(vars.mlx, rel_p, &img_w, &img_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

t_data	create_img(t_tools *tools, int w, int h)
{
	t_data	img;

	img.img = mlx_new_image(tools->vars->mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

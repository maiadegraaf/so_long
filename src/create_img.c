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
	//draw_t_hawks(tools, tools->t_hawks);
}

#define SHUT(x) (void)x;

void	draw_t_hawks(t_tools *tools, t_t_hawk_list *t_hawk)
{
	t_t_hawk_list	*tmp;

	tmp = t_hawk;
	while (tmp)
	{
		// SHUT(tools);
		// getchar();
		printf("x = %d\ty = %d\tcur_img = %d\n", tmp->t_hawk.x, tmp->t_hawk.y, tmp->t_hawk.cur_img);
		canvas_p_pixel_put(&tools->canvas, tmp->t_hawk.x, tmp->t_hawk.y, &tmp->t_hawk);
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

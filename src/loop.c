#include "../includes/so_long.h"

int	loop(t_tools *tools)
{
	t_enemy_list	*tmp;

	tools->i++;
	tmp = tools->enemys;
	while (tmp)
	{
		check_enemy(&tmp->enemy, tools);
		tmp = tmp->next;
	}
	check_tarantula(&tools->player, tools);
	draw_map(tools);
	if (tools->yum)
	{
		yummy(tools);
		tools->yum--;
	}
	else
		draw_info(tools, &tools->info);
	mlx_put_image_to_window(tools->vars->mlx, tools->vars->win, tools->canvas.img, 0, 0);
	return (0);
}

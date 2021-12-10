#include "../includes/so_long.h"

int	loop(t_tools *tools)
{
	if (check_tarantula(&tools->player, tools))
	{
		draw_map(tools);
	}
	if (tools->yum)
	{
		printf("yum yum yum\n");
		yummy(tools);
		tools->yum = 0;
	}
	else
		draw_info(tools, &tools->info);
	mlx_put_image_to_window(tools->vars->mlx, tools->vars->win, tools->canvas.img, 0, 0);
	return (0);
}
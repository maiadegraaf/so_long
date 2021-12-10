#include "../includes/so_long.h"

void	initiate_tarantula(t_tools *tools)
{
	tools->player.tarantula[0] = convert_xpm("img/tarantula/0.xpm", *tools->vars);
	tools->player.tarantula[1] = convert_xpm("img/tarantula/1.xpm", *tools->vars);
	tools->player.tarantula[2] = convert_xpm("img/tarantula/2.xpm", *tools->vars);
	tools->player.tarantula[3] = convert_xpm("img/tarantula/3.xpm", *tools->vars);
}

int	check_tarantula(t_player *player, t_tools *tools)
{
	if (player->new_x == player->x && player->new_y == player->y)
		return (0);
	else if (player->mv_pxl < SPRITE_SIZE && player->drawing == 0)
	{
		player->mv_pxl += 2;
		player->mv_x = player->mv_pxl * player->diff_x;
		player->mv_y = player->mv_pxl * player->diff_y;
		if (player->mv_pxl % 4 == 0)
			player->cur_img++;
		if (player->cur_img == 4)
			player->cur_img = 0;
	}
	else if (player->mv_pxl >= SPRITE_SIZE)
	{
		player->mv_pxl = 0;
		player->mv_x = 0;
		player->mv_y = 0;
		player->x = player->new_x;
		player->y = player->new_y;
		player->diff_x = 0;
		player->diff_y = 0;
		tools->moves++;
	}
	return (1);
}

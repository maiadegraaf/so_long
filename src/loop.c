/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:21:48 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:28:25 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	if_not_end_game(t_tools *tools)
{
	check_tarantula(&tools->player, tools);
	draw_map(tools);
	if (tools->yum)
	{
		yummy(tools);
		tools->yum--;
	}
	else
		draw_info(tools, &tools->info);
}

int	loop(t_tools *tools)
{
	tools->i++;
	if (tools->s_o)
		end_so_long(tools);
	else if (tools->g_o)
		game_over(tools);
	else
		if_not_end_game(tools);
	mlx_put_image_to_window(tools->vars->mlx, tools->vars->win,
		tools->canvas.img, 0, 0);
	return (0);
}

void	clear_player_info(t_player *player)
{
	player->mv_pxl = 0;
	player->mv_x = 0;
	player->mv_y = 0;
	player->x = player->new_x;
	player->y = player->new_y;
	player->diff_x = 0;
	player->diff_y = 0;
}

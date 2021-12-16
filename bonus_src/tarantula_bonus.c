/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tarantula_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:28:10 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:36:10 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	initiate_tarantula(t_tools *tools)
{
	tools->tarantulas.up[0] = convert_xpm("img/tarantula/up/0.xpm",
			*tools->vars);
	tools->tarantulas.up[1] = convert_xpm("img/tarantula/up/1.xpm",
			*tools->vars);
	tools->tarantulas.up[2] = convert_xpm("img/tarantula/up/2.xpm",
			*tools->vars);
	tools->tarantulas.up[3] = convert_xpm("img/tarantula/up/3.xpm",
			*tools->vars);
	tools->tarantulas.down[0] = convert_xpm("img/tarantula/down/0.xpm",
			*tools->vars);
	tools->tarantulas.down[1] = convert_xpm("img/tarantula/down/1.xpm",
			*tools->vars);
	tools->tarantulas.down[2] = convert_xpm("img/tarantula/down/2.xpm",
			*tools->vars);
	tools->tarantulas.down[3] = convert_xpm("img/tarantula/down/3.xpm",
			*tools->vars);
	initiate_tarantula_r_l(tools);
}

void	initiate_tarantula_r_l(t_tools *tools)
{
	tools->tarantulas.left[0] = convert_xpm("img/tarantula/left/0.xpm",
			*tools->vars);
	tools->tarantulas.left[1] = convert_xpm("img/tarantula/left/1.xpm",
			*tools->vars);
	tools->tarantulas.left[2] = convert_xpm("img/tarantula/left/2.xpm",
			*tools->vars);
	tools->tarantulas.left[3] = convert_xpm("img/tarantula/left/3.xpm",
			*tools->vars);
	tools->tarantulas.right[0] = convert_xpm("img/tarantula/right/0.xpm",
			*tools->vars);
	tools->tarantulas.right[1] = convert_xpm("img/tarantula/right/1.xpm",
			*tools->vars);
	tools->tarantulas.right[2] = convert_xpm("img/tarantula/right/2.xpm",
			*tools->vars);
	tools->tarantulas.right[3] = convert_xpm("img/tarantula/right/3.xpm",
			*tools->vars);
}

int	check_tarantula(t_player *player, t_tools *tools)
{
	if (player->new_x == player->x && player->new_y == player->y)
		return (0);
	else if (player->mv_pxl < SPRITE_SIZE)
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
		clear_player_info(player);
		tools->moves++;
		ft_printf("moves = %d\n", tools->moves);
	}
	return (1);
}

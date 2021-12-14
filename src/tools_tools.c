/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 09:21:49 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/14 10:22:23 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initiate_tools(t_tools *tools)
{
	initialize_extra_img(tools);
	find_start(&tools);
	find_walls(&tools);
	find_exits(&tools);
	find_bugs(&tools);
	tools->moves = 0;
	tools->player.mv_pxl = 0;
	tools->player.mv_x = 0;
	tools->player.mv_y = 0;
	tools->player.cur_img = 0;
	tools->player.diff_x = 0;
	tools->player.diff_y = 0;
	tools->player.diff_y = 0;
	tools->player.img = tools->tarantulas.up;
	tools->yum = 0;
	assign_bugs(tools);
	tools->i = 0;
	init_enemy_frames(tools);
	tools->empty = determine_empty_space(tools->map);
	tools->num_enemys = determine_num_enemys(tools->empty);
	tools->enemys = NULL;
	if (tools->num_enemys)
		create_enemy_list(tools);
}

void	initialize_extra_img(t_tools *tools)
{
	tools->g_o = 0;
	tools->s_o = 0;
	tools->j = 0;
	tools->sand = convert_xpm("img/sand.xpm", *tools->vars);
	tools->cactus = convert_xpm("img/cactus.xpm", *tools->vars);
	tools->hovel = convert_xpm("img/hovel.xpm", *tools->vars);
	tools->yummy[0] = convert_xpm("img/yum/Y.xpm", *tools->vars);
	tools->yummy[1] = convert_xpm("img/yum/U.xpm", *tools->vars);
	tools->yummy[2] = convert_xpm("img/yum/M.xpm", *tools->vars);
	initialize_info(tools);
	initiate_tarantula(tools);
	initiate_end_game(tools);
	initiate_bug(tools);
	create_canvas(tools);
}

void	create_canvas(t_tools *tools)
{
	if (tools->map_w * SPRITE_SIZE < tools->info.info_w)
		tools->map_pxl_w = tools->info.info_w;
	else
		tools->map_pxl_w = tools->map_w * SPRITE_SIZE;
	tools->map_pxl_h = (tools->map_h * SPRITE_SIZE) + tools->info.info_h;
	tools->canvas = create_img(tools, tools->map_pxl_w, tools->map_pxl_h);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 09:21:49 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/13 18:21:47 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initiate_tools(t_tools *tools)
{
	initialize_extra_img(tools);
	initialize_info(tools);
	create_canvas(tools);
	find_start(&tools);
	find_walls(&tools);
	find_bugs(&tools);
	initiate_bug(tools);
	initiate_tarantula(tools);
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
	initiate_end_game(tools);
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

void	find_walls(t_tools **tools)
{
	t_map	*tmp;
	t_map	*walls;
	t_map	*node;

	walls = NULL;
	tmp = (*tools)->map;
	while (tmp)
	{
		if (tmp->content == '1')
		{
			node = ft_mapnew(tmp->x, tmp->y, tmp->content);
			if (!node)
			{
				ft_mapclear(&walls);
				return ;
			}
			ft_mapadd_back(&walls, node);
		}	
		tmp = tmp->next;
	}
	(*tools)->walls = walls;
}

int	find_start(t_tools **tools)
{
	t_map	*tmp;

	tmp = (*tools)->map;
	while (tmp)
	{
		if (tmp->content == 'P')
		{
			(*tools)->player.x = tmp->x;
			(*tools)->player.y = tmp->y;
		}
		if (tmp->content == 'E')
		{
			(*tools)->e_x = tmp->x;
			(*tools)->e_y = tmp->y;
		}
		tmp = tmp->next;
	}
	(*tools)->player.new_x = (*tools)->player.x;
	(*tools)->player.new_y = (*tools)->player.y;
	return (1);
}

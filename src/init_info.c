/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_info.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:22:16 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/14 09:21:25 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_info(t_tools *tools)
{
	if (tools->map_w < 8)
	{
		tools->info.info_w = 4 * SPRITE_SIZE;
		tools->info.info_h = 2 * SPRITE_SIZE;
	}
	else
	{
		tools->info.info_w = 8 * SPRITE_SIZE;
		tools->info.info_h = SPRITE_SIZE;
	}
	tools->info.bugs[0] = convert_xpm("img/info/bugs/B.xpm", *tools->vars);
	tools->info.bugs[1] = convert_xpm("img/info/bugs/U.xpm", *tools->vars);
	tools->info.bugs[2] = convert_xpm("img/info/bugs/G.xpm", *tools->vars);
	tools->info.bugs[3] = convert_xpm("img/info/bugs/S.xpm", *tools->vars);
	tools->info.moves[0] = convert_xpm("img/info/moves/M.xpm", *tools->vars);
	tools->info.moves[1] = convert_xpm("img/info/moves/O.xpm", *tools->vars);
	tools->info.moves[2] = convert_xpm("img/info/moves/V.xpm", *tools->vars);
	tools->info.moves[3] = convert_xpm("img/info/moves/E.xpm", *tools->vars);
	tools->info.moves[4] = convert_xpm("img/info/moves/S.xpm", *tools->vars);
	tools->info.blank = convert_xpm("img/info/blank.xpm", *tools->vars);
	tools->info.err[0] = convert_xpm("img/info/ERR/E.xpm", *tools->vars);
	tools->info.err[1] = convert_xpm("img/info/ERR/R.xpm", *tools->vars);
	initialize_numbers(&tools->info, tools->vars);
}

void	initialize_numbers(t_info *info, t_vars *vars)
{
	info->num[0] = convert_xpm("img/info/nums/0.xpm", *vars);
	info->num[1] = convert_xpm("img/info/nums/1.xpm", *vars);
	info->num[2] = convert_xpm("img/info/nums/2.xpm", *vars);
	info->num[3] = convert_xpm("img/info/nums/3.xpm", *vars);
	info->num[4] = convert_xpm("img/info/nums/4.xpm", *vars);
	info->num[5] = convert_xpm("img/info/nums/5.xpm", *vars);
	info->num[6] = convert_xpm("img/info/nums/6.xpm", *vars);
	info->num[7] = convert_xpm("img/info/nums/7.xpm", *vars);
	info->num[8] = convert_xpm("img/info/nums/8.xpm", *vars);
	info->num[9] = convert_xpm("img/info/nums/9.xpm", *vars);
}

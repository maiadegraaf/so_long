/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_info_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:18:32 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:36:10 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_info(t_tools *tools, t_info *info)
{
	int	x_y[2];
	int	i_j[2];

	x_y[0] = 0;
	x_y[1] = tools->map_h * SPRITE_SIZE;
	i_j[0] = tools->map_pxl_w;
	i_j[1] = tools->map_pxl_h;
	color_box(x_y, i_j, &tools->canvas, 0xE68B40);
	x_y[1] = tools->map_h;
	draw_moves_info(tools, info, x_y, tools->moves);
	if (tools->map_w < 8)
		draw_bug_info_double(tools, info, x_y, tools->num_bugs);
	else
		draw_bug_info(tools, info, x_y, tools->num_bugs);
}

void	draw_moves_info(t_tools *tools, t_info *info, int x_y[2], int moves)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		canvas_info_pixel_put(20, x_y, &tools->canvas, &info->moves[i++]);
		x_y[0]++;
	}
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->blank);
	x_y[0]++;
	if (moves > 999)
	{
		draw_error(tools, info, x_y);
		return ;
	}
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[moves / 100]);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[moves / 10 % 10]);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[moves % 10]);
}

void	draw_bug_info_double(t_tools *tools, t_info *info, int x_y[2], int bugs)
{
	int	i;

	i = 0;
	x_y[0] = 0;
	x_y[1] += 1;
	while (i < 4)
	{
		canvas_info_pixel_put(20, x_y, &tools->canvas, &info->bugs[i++]);
		x_y[0]++;
	}
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->blank);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->blank);
	x_y[0]++;
	if (bugs > 999)
	{
		draw_error(tools, info, x_y);
		return ;
	}
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[bugs / 100]);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[bugs / 10 % 10]);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[bugs % 10]);
}

void	draw_bug_info(t_tools *tools, t_info *info, int x_y[2], int bugs)
{
	int	i;

	i = 3;
	x_y[0] = (tools->map_w * 2) - 1;
	if (bugs < 1000)
	{
		canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[bugs % 10]);
		x_y[0]--;
		canvas_info_pixel_put(20, x_y, &tools->canvas,
			&info->num[bugs / 10 % 10]);
		x_y[0]--;
		canvas_info_pixel_put(20, x_y, &tools->canvas, &info->num[bugs / 100]);
		x_y[0]--;
		canvas_info_pixel_put(20, x_y, &tools->canvas, &info->blank);
		x_y[0]--;
	}
	else
		x_y[0] = draw_error(tools, info, x_y);
	while (i > -1)
	{
		canvas_info_pixel_put(20, x_y, &tools->canvas, &info->bugs[i--]);
		x_y[0]--;
	}
}

int	draw_error(t_tools *tools, t_info *info, int x_y[2])
{
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->err[0]);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->err[1]);
	x_y[0]++;
	canvas_info_pixel_put(20, x_y, &tools->canvas, &info->err[1]);
	return (x_y[0]);
}

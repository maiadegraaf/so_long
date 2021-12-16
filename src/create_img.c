/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_img.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:17:44 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:37:06 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_tools *tools)
{
	t_map	*tmp;
	t_bugs	*b_tmp;

	tmp = tools->map;
	mlx_destroy_image(tools->vars->mlx, tools->canvas.img);
	create_canvas(tools);
	while (tmp)
	{
		canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &tools->sand);
		if (tmp->content == '1')
			canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &tools->cactus);
		if (tmp->content == 'E')
			canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &tools->hovel);
		if (tmp->content == 'C')
		{
			b_tmp = locate_bug(tools->bugs, tmp->x, tmp->y);
			canvas_pixel_put(&tools->canvas, tmp->x, tmp->y, &b_tmp->bug);
		}
		tmp = tmp->next;
	}
	canvas_p_pixel_put(&tools->canvas, tools->player.x,
		tools->player.y, &tools->player);
}

t_bugs	*locate_bug(t_bugs	*bugs, int x, int y)
{
	t_bugs	*b_tmp;

	b_tmp = bugs;
	while (b_tmp)
	{
		if (b_tmp->x == x && b_tmp->y == y)
			return (b_tmp);
		b_tmp = b_tmp->next;
	}
	return (NULL);
}

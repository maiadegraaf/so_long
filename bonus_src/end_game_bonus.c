/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_game_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 16:24:39 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 14:36:10 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	calculate_w_buff(t_tools *tools)
{
	return (((tools->map_w - 4) / 2));
}

int	calculate_h_buff(t_tools *tools)
{
	return ((tools->map_h - 2) / 2);
}

void	canvas_end_pixel_put(int x_y[2], t_data *canvas, t_data *sprite)
{
	char			*dst;
	int				pix_y;
	int				pix_x;
	unsigned int	color;

	pix_y = 0;
	while (pix_y < 120)
	{
		pix_x = 0;
		while (pix_x < 200)
		{	
			color = *(unsigned int *)(sprite->addr + (pix_x * \
					sprite->bits_per_pixel / 8 + pix_y * sprite->line_length));
			if (color != 0xFF000000)
				dst = canvas->addr + \
						((x_y[1] * SPRITE_SIZE + pix_y) * canvas->line_length \
						+ (x_y[0] * SPRITE_SIZE + pix_x) \
						* (canvas->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			pix_x++;
		}	
		pix_y++;
	}
}

void	game_over(t_tools *tools)
{
	int	x_y[2];
	int	i_j[2];

	x_y[0] = 0;
	x_y[1] = 0;
	i_j[0] = tools->map_pxl_w;
	i_j[1] = tools->map_pxl_h;
	color_box(x_y, i_j, &tools->canvas, 0x021D30);
	x_y[1] = calculate_h_buff(tools);
	x_y[0] = calculate_w_buff(tools);
	if (tools->i % 10 == 0)
		tools->j++;
	if (tools->j == 6)
		tools->j = 0;
	canvas_end_pixel_put(x_y, &tools->canvas, &tools->game_over[tools->j]);
}

void	end_so_long(t_tools *tools)
{
	int	x_y[2];
	int	i;
	int	j;

	i = 0;
	while (i < tools->map_h)
	{
		j = 0;
		while (j < tools->map_w)
		{
			canvas_pixel_put(&tools->canvas, j, i, &tools->sand);
			j++;
		}
		i++;
	}
	x_y[1] = calculate_h_buff(tools);
	x_y[0] = calculate_w_buff(tools);
	i = 0;
	if (tools->i % 10 == 0)
		tools->j++;
	if (tools->j == 4)
		tools->j = 0;
	canvas_end_pixel_put(x_y, &tools->canvas, &tools->so_long[tools->j]);
}

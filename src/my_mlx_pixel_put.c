/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_pixel_put.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:25:25 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/13 15:27:11 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	canvas_pixel_put(t_data *canvas, int x, int y, t_data *sprite)
{
	char			*dst;
	int				pix_y;
	int				pix_x;
	unsigned int	color;

	pix_y = 0;
	while (pix_y < SPRITE_SIZE)
	{
		pix_x = 0;
		while (pix_x < SPRITE_SIZE)
		{	
			color = *(unsigned int *)(sprite->addr + (pix_x * \
					sprite->bits_per_pixel / 8 + pix_y * sprite->line_length));
			if (color != 0xFF000000)
			{
				dst = canvas->addr + \
						((y * SPRITE_SIZE + pix_y) * canvas->line_length \
						+ (x * SPRITE_SIZE + pix_x) \
						* (canvas->bits_per_pixel / 8));
				*(unsigned int *)dst = color;
			}	
			pix_x++;
		}
		pix_y++;
	}
}

void	canvas_info_pixel_put(int w, int x_y[2], t_data *canvas, t_data *sprite)
{
	char			*dst;
	int				pix_y;
	int				pix_x;
	unsigned int	color;

	pix_y = 0;
	while (pix_y < SPRITE_SIZE)
	{
		pix_x = 0;
		while (pix_x < w)
		{	
			color = *(unsigned int *)(sprite->addr + (pix_x * \
					sprite->bits_per_pixel / 8 + pix_y * sprite->line_length));
			dst = canvas->addr + \
					((x_y[1] * SPRITE_SIZE + pix_y) * canvas->line_length \
					+ (x_y[0] * w + pix_x) \
					* (canvas->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			pix_x++;
		}	
		pix_y++;
	}
}

void	canvas_p_pixel_put(t_data *canvas, int x, int y, t_player *player)
{
	int				pix_y;
	int				pix_x;
	unsigned int	color;

	pix_y = 0;
	while (pix_y < SPRITE_SIZE)
	{
		pix_x = 0;
		while (pix_x < SPRITE_SIZE)
		{
			color = *(unsigned int *)(player->img[player->cur_img].addr + \
					(pix_x * player->img[player->cur_img].bits_per_pixel \
					/ 8 + pix_y * \
					player->img[player->cur_img].line_length));
			if (color != 0xFF000000)
				my_mlx_pixel_put(canvas,
					(x * SPRITE_SIZE + pix_x + player->mv_x),
					(y * SPRITE_SIZE + pix_y + player->mv_y), color);
			pix_x++;
		}
		pix_y++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

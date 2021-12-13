/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   img_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:12:17 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/13 18:17:42 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	color_box(int x_y[2], int i_j[2], t_data *img, int color)
{
	int	k;

	while (x_y[1] < i_j[1])
	{
		k = x_y[0];
		while (k < i_j[0])
		{
			my_mlx_pixel_put(img, k, x_y[1], color);
			k++;
		}
		x_y[1]++;
	}
}

t_data	convert_xpm(char *rel_p, t_vars vars)
{
	t_data	img;
	int		img_w;
	int		img_h;

	img.img = mlx_xpm_file_to_image(vars.mlx, rel_p, &img_w, &img_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

t_data	create_img(t_tools *tools, int w, int h)
{
	t_data	img;

	img.img = mlx_new_image(tools->vars->mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	initiate_end_game(t_tools *tools)
{
	tools->game_over[0] = convert_xpm("img/game_over/0.xpm", *tools->vars);
	tools->game_over[1] = convert_xpm("img/game_over/1.xpm", *tools->vars);
	tools->game_over[2] = convert_xpm("img/game_over/2.xpm", *tools->vars);
	tools->game_over[3] = convert_xpm("img/game_over/3.xpm", *tools->vars);
	tools->game_over[4] = convert_xpm("img/game_over/4.xpm", *tools->vars);
	tools->game_over[5] = convert_xpm("img/game_over/5.xpm", *tools->vars);
	tools->so_long[0] = convert_xpm("img/so_long/0.xpm", *tools->vars);
	tools->so_long[1] = convert_xpm("img/so_long/1.xpm", *tools->vars);
	tools->so_long[2] = convert_xpm("img/so_long/2.xpm", *tools->vars);
	tools->so_long[3] = convert_xpm("img/so_long/3.xpm", *tools->vars);
	tools->so_long[4] = convert_xpm("img/so_long/4.xpm", *tools->vars);
	tools->so_long[5] = convert_xpm("img/so_long/5.xpm", *tools->vars);
}
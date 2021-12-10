/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_create_canvas.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 01:05:36 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/10/28 13:20:01 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

// TODO: Check for errors :D
t_canvas	*ft_create_canvas(t_mlx *mlx, t_i32 width, t_i32 height)
{
	t_canvas	*out;

	out = malloc(sizeof(t_canvas));
	out->width = width;
	out->height = height;
	out->img = mlx_new_image(mlx->mlx, width, height);
	out->pixels = mlx_get_data_addr(out->img, &out->bits_per_pixel, \
	&out->line_length, &out->endian);
	return (out);
}

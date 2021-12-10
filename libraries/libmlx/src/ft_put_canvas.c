/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_canvas.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 11:56:38 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/10/31 11:58:29 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_i32	ft_put_canvas(t_mlx *mlx, t_canvas *canvas, t_point pos)
{
	return (mlx_put_image_to_window(mlx->mlx, mlx->win, canvas->img, \
	pos.x, pos.y));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_pixel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 11:19:07 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/01 19:46:54 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void	ft_set_pixel(t_canvas *canvas, t_point point, t_i32 color)
{
	if (canvas && point.x > 0 && point.y > 0)
	{
		if (point.x < canvas->width && point.y >= 0 && point.y < canvas->height)
			*ft_get_pixel(canvas, point) = color;
	}
}

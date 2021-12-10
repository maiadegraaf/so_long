/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_pixel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 11:18:45 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/01 17:55:54 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_i32	*ft_get_pixel(t_canvas *canvas, t_point point)
{
	char	*dst;

	if (!(point.x < canvas->width && point.y >= 0 && point.y < canvas->height))
		return (NULL);
	dst = canvas->pixels + (point.y * canvas->line_length + point.x * \
	(canvas->bits_per_pixel / 8));
	return ((t_i32 *)dst);
}

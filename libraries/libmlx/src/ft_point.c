/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_point.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 14:55:43 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/10/27 14:57:24 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_point	ft_point(t_i32 X, t_i32 Y)
{
	t_point	out;

	out.x = X;
	out.y = Y;
	return (out);
}

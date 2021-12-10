/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw_line.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 14:37:37 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/30 18:54:00 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static t_i32	ft_select(t_bool Val, t_i32 a, t_i32 b)
{
	if (Val)
		return (a);
	return (b);
}

static	void	ft_setup(t_point s, t_point e, t_point *delta, t_point *incr)
{
	delta->x = ft_abs(s.x - e.x);
	delta->y = ft_abs(s.y - e.y);
	incr->x = ft_select(e.x < s.x, 1, -1);
	incr->y = ft_select(e.y < s.y, 1, -1);
}

void	ft_draw_line(t_canvas *canvas, t_point s, t_point e)
{
	t_point	delta;
	t_point	incr;
	t_point	cur;
	t_i32	error;

	ft_setup(s, e, &delta, &incr);
	error = 2 * (delta.y - delta.x);
	cur = e;
	while (true)
	{
		ft_set_pixel(canvas, cur, BRICK_RED);
		if (cur.x == s.x && cur.y == s.y)
			break ;
		if (error >= 0)
		{
			cur.y += incr.y;
			error -= 2 * delta.x;
		}
		if (error < 0)
		{
			cur.x += incr.x;
			error += 2 * delta.y;
		}
	}
}

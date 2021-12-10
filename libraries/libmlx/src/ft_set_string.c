/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_string.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 18:41:55 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/10/28 00:09:59 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void	ft_set_string(t_mlx *mlx, t_point pos, int color, char *text)
{
	mlx_string_put(mlx->mlx, mlx->win, pos.x, pos.y, color, text);
}

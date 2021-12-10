/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 18:30:27 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/09 10:28:21 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_bool	ft_init(t_mlx *mlx_out, t_u32 width, t_u32 height, char	*title)
{
	if (width <= 0 || height <= 0 || width >= I16_MAX || height >= I16_MAX)
		return (false);
	mlx_out->mlx = mlx_init();
	if (!mlx_out->mlx)
		return (false);
	mlx_out->win = mlx_new_window(mlx_out->mlx, width, height, title);
	if (!mlx_out->win)
		return (false);
	return (ft_clear_window(mlx_out));
}

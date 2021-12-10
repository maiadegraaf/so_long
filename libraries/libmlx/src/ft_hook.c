/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hook.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 13:55:14 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/03 14:04:14 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_i32	ft_hook(t_mlx *mlx, t_u32 event, int (*func)(), void *param)
{
	if (!mlx || !mlx->mlx || event < 2 || !func)
		return (0);
	return (mlx_hook(mlx->win, event, 0, func, param));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_key_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 10:47:18 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/09 09:58:28 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_i32	ft_key_hook(t_mlx *mlx, t_i32 (*func)(), void *param)
{
	return (mlx_key_hook(mlx->win, func, param));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clear_window.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 18:26:47 by lde-la-h      #+#    #+#                 */
/*   Updated: 2021/11/09 10:27:38 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

t_bool	ft_clear_window(t_mlx *mlx)
{
	return (mlx_clear_window(mlx->mlx, mlx->win));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:27:24 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/14 09:29:51 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extra_keys(int key_code, t_tools *tools)
{
	if (key_code == ESC)
	{
		mlx_destroy_window(tools->vars->mlx, tools->vars->win);
		exit(0);
	}
	if (key_code == KEY_R)
	{
		so_long(tools);
	}
	return (0);
}

void	so_long(t_tools *tools)
{
	initiate_tools(tools);
	tools->vars->win = mlx_new_window(tools->vars->mlx, tools->map_pxl_w,
			tools->map_pxl_h, "eat ur bugs");
	draw_map(tools);
}

int	main(int argc, char **argv)
{
	t_tools	tools;
	t_vars	vars;

	if (argc == 1)
		return (0);
	if (check_ber(argv[1]) || generate_map(argv[1], &tools))
	{
		printf ("ERROR\n");
		return (1);
	}
	vars.mlx = mlx_init();
	tools.vars = &vars;
	//so_long(&tools);
	initiate_tools(&tools);
	tools.vars->win = mlx_new_window(tools.vars->mlx, tools.map_pxl_w,
			tools.map_pxl_h, "eat ur bugs");
	draw_map(&tools);
	mlx_key_hook(tools.vars->win, extra_keys, &tools);
	mlx_hook(tools.vars->win, 2, (1L << 0), check_wasd, &tools);
	mlx_loop_hook(tools.vars->mlx, loop, &tools);
	mlx_loop(tools.vars->mlx);
}

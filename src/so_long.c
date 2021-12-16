/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:27:24 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/14 21:31:54 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	extra_keys(int key_code, t_tools *tools)
{
	if (key_code == ESC)
	{
		destroy_window(tools);
	}
	return (0);
}

int	destroy_window(t_tools *tools)
{
	mlx_destroy_window(tools->vars->mlx, tools->vars->win);
	free_all(tools);
	system("leaks so_long");
	exit(0);
}

void	destroy_img_frames(t_data *img, void *mlx, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		mlx_destroy_image(mlx, img[i].img);
		i++;
	}
}

void	free_all(t_tools *tools)
{
	ft_mapclear(&tools->map);
	ft_mapclear(&tools->exit);
	ft_mapclear(&tools->walls);
	ft_bugsclear(&tools->bugs);
	ft_enemy_listclear(&tools->enemys);
	destroy_img_frames(tools->tarantulas.up, tools->vars->mlx, 4);
	destroy_img_frames(tools->tarantulas.down, tools->vars->mlx, 4);
	destroy_img_frames(tools->tarantulas.left, tools->vars->mlx, 4);
	destroy_img_frames(tools->tarantulas.right, tools->vars->mlx, 4);
	destroy_img_frames(tools->yummy, tools->vars->mlx, 3);
	destroy_img_frames(tools->bug, tools->vars->mlx, 3);
	destroy_img_frames(tools->enemy, tools->vars->mlx, 4);
	destroy_img_frames(tools->game_over, tools->vars->mlx, 6);
	destroy_img_frames(tools->so_long, tools->vars->mlx, 4);
	destroy_img_frames(tools->info.num, tools->vars->mlx, 10);
	destroy_img_frames(tools->info.bugs, tools->vars->mlx, 4);
	destroy_img_frames(tools->info.moves, tools->vars->mlx, 5);
	destroy_img_frames(tools->info.err, tools->vars->mlx, 2);
	mlx_destroy_image(tools->vars->mlx, tools->info.blank.img);
	mlx_destroy_image(tools->vars->mlx, tools->canvas.img);
	mlx_destroy_image(tools->vars->mlx, tools->sand.img);
	mlx_destroy_image(tools->vars->mlx, tools->cactus.img);
	mlx_destroy_image(tools->vars->mlx, tools->hovel.img);
}

/*
TO DO:

-> seperate bonus;
*/

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
	initiate_tools(&tools);
	tools.vars->win = mlx_new_window(tools.vars->mlx, tools.map_pxl_w,
			tools.map_pxl_h, "eat ur bugs");
	draw_map(&tools);
	mlx_hook(tools.vars->win, 17, 0, destroy_window, &tools);
	mlx_key_hook(tools.vars->win, extra_keys, &tools);
	mlx_hook(tools.vars->win, 2, (1L << 0), check_wasd, &tools);
	mlx_loop_hook(tools.vars->mlx, loop, &tools);
	mlx_loop(tools.vars->mlx);
}

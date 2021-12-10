#include "../includes/so_long.h"

int	ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str != c)
	{
		i++;
		str++;
	}
	return (i);
}

int	check_ber(char *input)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(input, '.');
	if (ft_strncmp("ber", split[1], ft_strlen(split[1])))
		i++;
	free_arr(split);
	free(split);
	return (i);
}

void	clear_map(t_map	*map)
{
	ft_mapclear(&map);
	free(map);
}

int	escape(int key_code, t_tools *tools)
{
	if (key_code == ESC)
	{
		mlx_destroy_window(tools->vars->mlx, tools->vars->win);
		exit(0);
	}
	return (0);
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
	initiate_tools(&tools);
	printf("in main %d, %d\n", tools.t_hawks->t_hawk->x, tools.t_hawks->t_hawk->y);
	tools.vars->win = mlx_new_window(tools.vars->mlx, tools.map_pxl_w,
			tools.map_pxl_h, "eat ur bugs");
	draw_map(&tools);
	mlx_put_image_to_window(tools.vars->mlx, tools.vars->win, tools.canvas.img, 0, 0);
	// mlx_key_hook(tools.vars->win, escape, &tools);
	// mlx_hook(tools.vars->win, 2, (1L << 0), check_wasd, &tools);
	// mlx_loop_hook(tools.vars->mlx, loop, &tools);
	mlx_loop(tools.vars->mlx);
}

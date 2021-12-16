/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   generate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 09:21:37 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/16 13:54:59 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	convert_map(char *init, t_map **map, int y)
{
	int		x;
	t_map	*node;

	x = 0;
	while (init[x] && init[x] != '\n')
	{
		node = ft_mapnew(x, y, init[x]);
		if (!node)
		{
			ft_mapclear(map);
			return (0);
		}
		ft_mapadd_back(map, node);
		x++;
	}
	return (x - 1);
}

void	generate_map(char *input, t_tools *tools)
{
	char	*init;
	int		fd;

	tools->map_h = 0;
	fd = open(input, O_RDONLY);
	init = get_next_line(fd);
	if (!init)
		ft_error(3);
	tools->map_w = ft_strlen_c(init, '\n');
	tools->map = NULL;
	while (init)
	{
		if (convert_map(init, &tools->map, tools->map_h) != tools->map_w - 1)
		{
			clear_map(tools->map);
			ft_error(1);
		}
		tools->map_h++;
		free(init);
		init = get_next_line(fd);
	}
	free(init);
	check_invalid(tools->map, tools->map_w, tools->map_h);
}

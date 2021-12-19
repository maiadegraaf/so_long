/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bugs.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:10:14 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/16 16:40:25 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_bugs(t_tools **tools)
{
	t_map	*tmp;
	t_bugs	*bugs;
	t_bugs	*node;

	bugs = NULL;
	(*tools)->num_bugs = 0;
	tmp = (*tools)->map;
	while (tmp)
	{
		if (tmp->content == 'C')
		{
			node = ft_bugsnew(tmp->x, tmp->y, tmp->content);
			if (!node)
			{
				ft_bugsclear(&bugs);
				return ;
			}
			ft_bugsadd_back(&bugs, node);
			(*tools)->num_bugs++;
		}	
		tmp = tmp->next;
	}
	(*tools)->bugs = bugs;
}

void	initiate_bug(t_tools *tools)
{
	tools->bug[0] = convert_xpm("img/bugs/bug1.xpm", *tools->vars);
	tools->bug[1] = convert_xpm("img/bugs/bug2.xpm", *tools->vars);
	tools->bug[2] = convert_xpm("img/bugs/bug3.xpm", *tools->vars);
}	

void	assign_bugs(t_tools *tools)
{
	t_bugs	*tmp;
	int		i;

	i = 0;
	tmp = tools->bugs;
	while (tmp)
	{
		if (i == 3)
			i = 0;
		tmp->bug = tools->bug[i];
		i++;
		tmp = tmp->next;
	}
}

void	yummy(t_tools *tools)
{
	int	x_y[2];
	int	i;

	x_y[0] = 0;
	x_y[1] = tools->map_h;
	while (x_y[0] < tools->map_w * 2)
	{
		i = 0;
		while (i < 3 && x_y[0] < tools->map_w * 2)
		{
			canvas_info_pixel_put(20, x_y, &tools->canvas, &tools->yummy[i]);
			i++;
			x_y[0]++;
		}
		if (x_y[0] < tools->map_w * 2)
			canvas_info_pixel_put(20, x_y, &tools->canvas, &tools->info.blank);
		x_y[0]++;
	}
}

int	change_coordinate(t_tools *tools)
{
	t_map	*tmp;

	tmp = tools->map;
	while (tmp)
	{
		if (tmp->x == tools->player.new_x && tmp->y == tools->player.new_y)
		{
			tmp->content = '0';
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

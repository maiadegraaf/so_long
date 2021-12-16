/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 09:29:37 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/16 13:54:53 by mgraaf        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_error(int i)
{
	ft_printf("Error\n");
	if (i == 0)
		ft_printf("Incorrect file type\n");
	if (i == 1)
		ft_printf("Incomplete map\n");
	if (i == 2)
		ft_printf("Found incompatible character\n");
	if (i == 4)
		ft_printf("Unable to locate the player's starting position\n");
	if (i == 5)
		ft_printf("Unable to locate collectables\n");
	if (i == 6)
		ft_printf("Unable to locate the exit\n");
	if (i == 7)
		ft_printf("Map not surrounded by walls\n");
	if (i == 3)
		ft_printf("No input\n");
	exit(EXIT_FAILURE);
}

int	check_ber(char *input)
{
	char	**split;
	int		i;

	i = 0;
	if (!ft_strchr(input, '.'))
		ft_error(0);
	split = ft_split(input, '.');
	if (ft_strncmp("ber", split[1], ft_strlen(split[1])))
		i++;
	free_arr(split);
	free(split);
	if (i != 0)
		ft_error(0);
	return (i);
}

void	clear_map(t_map	*map)
{
	ft_mapclear(&map);
	free(map);
}

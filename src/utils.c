/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maiadegraaf <maiadegraaf@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 09:29:37 by maiadegraaf   #+#    #+#                 */
/*   Updated: 2021/12/14 09:30:04 by maiadegraaf   ########   odam.nl         */
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

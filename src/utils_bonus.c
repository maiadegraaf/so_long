#include "../includes/so_long.h"

/**
 * Creates a random number.
 * 
 * @param weight 0-100 Percentage chance for true or false.
 * @return Either true or false.
 */
int	ft_rand(int weight)
{
	return ((rand() % 100) < weight);
}

int	determine_empty_space(t_map *map)
{
	int e;
	t_map	*tmp;

	tmp = map;
	e = 0;
	while (tmp)
	{
		if (tmp->content == '0')
			e++;
		tmp = tmp->next;
	}
	return (e);
}
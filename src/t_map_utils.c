#include "../includes/so_long.h"

t_map	*ft_mapnew(int x, int y, char content)
{
	t_map	*new_element;

	new_element = (t_map *)malloc(sizeof(t_map));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->x = x;
	new_element->y = y;
	new_element->next = NULL;
	return (new_element);
}

void	ft_mapadd_back(t_map **lst, t_map *new)
{
	t_map	*tmp;

	tmp = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_mapadd_front(t_map **lst, t_map *new)
{
	t_map	*tmp;

	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	printf("HELLO\n");
	new->next = *lst;
	*lst = new;
	tmp = *lst;
	tmp = tmp->next;
	while (tmp != NULL)
		tmp = tmp->next;
}

void	ft_mapclear(t_map **lst)
{
	t_map	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_map	*ft_maplast(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->next != NULL)
	{
		map = map->next;
		i++;
	}
	return (map);
}

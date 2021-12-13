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

void	ft_mapdelone(t_map **lst, char key)
{
	t_map	*node;
	t_map	*prev;
	t_map	*start;

	start = *lst;
	node = start;
	if ((*lst)->content == key)
	{
		*lst = node->next;
		free(node);
		return ;
	}
	while (node && node->content != key)
	{
		prev = node;
		node = node->next;
	}
	prev->next = node->next;
	free(node);
	*lst = start;
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

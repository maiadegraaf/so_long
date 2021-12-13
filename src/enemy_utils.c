#include "../includes/so_long.h"

t_enemy_list	*ft_enemy_listnew(t_player *enemy)
{
	t_enemy_list	*new_element;

	new_element = (t_enemy_list *)malloc(sizeof(t_enemy_list));
	if (!new_element)
		return (0);
	ft_memcpy(&new_element->enemy, enemy, sizeof(enemy));
	new_element->next = NULL;
	return (new_element);
}

void	ft_enemy_listadd_back(t_enemy_list **lst, t_enemy_list *new)
{
	t_enemy_list	*tmp;

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

void	ft_enemy_listadd_front(t_enemy_list **lst, t_enemy_list *new)
{
	t_enemy_list	*tmp;

	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
	tmp = *lst;
	tmp = tmp->next;
	while (tmp != NULL)
		tmp = tmp->next;
}

void	ft_enemy_listclear(t_enemy_list **lst)
{
	t_enemy_list	*tmp;

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

t_enemy_list	*ft_enemy_listlast(t_enemy_list *bugs)
{
	int	i;

	i = 0;
	if (!bugs)
		return (NULL);
	while (bugs->next != NULL)
	{
		bugs = bugs->next;
		i++;
	}
	return (bugs);
}

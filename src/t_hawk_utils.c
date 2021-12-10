#include "../includes/so_long.h"

t_t_hawk_list	*ft_t_hawk_listnew(t_player *t_hawk)
{
	t_t_hawk_list	*new_element;

	new_element = (t_t_hawk_list *)malloc(sizeof(t_t_hawk_list));
	if (!new_element)
		return (0);
	new_element->t_hawk = t_hawk;
	new_element->next = NULL;
	return (new_element);
}

void	ft_t_hawk_listadd_back(t_t_hawk_list **lst, t_t_hawk_list *new)
{
	t_t_hawk_list	*tmp;

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

void	ft_t_hawk_listadd_front(t_t_hawk_list **lst, t_t_hawk_list *new)
{
	t_t_hawk_list	*tmp;

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

void	ft_t_hawk_listclear(t_t_hawk_list **lst)
{
	t_t_hawk_list	*tmp;

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

t_t_hawk_list	*ft_t_hawk_listlast(t_t_hawk_list *bugs)
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

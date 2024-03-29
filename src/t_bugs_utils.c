/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_bugs_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgraaf <mgraaf@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 15:27:52 by mgraaf        #+#    #+#                 */
/*   Updated: 2021/12/14 11:38:11 by maiadegraaf   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bugs	*ft_bugsnew(int x, int y, char content)
{
	t_bugs	*new_element;

	new_element = (t_bugs *)malloc(sizeof(t_bugs));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->x = x;
	new_element->y = y;
	new_element->next = NULL;
	return (new_element);
}

void	ft_bugsadd_back(t_bugs **lst, t_bugs *new)
{
	t_bugs	*tmp;

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

void	ft_bugsadd_front(t_bugs **lst, t_bugs *new)
{
	t_bugs	*tmp;

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

void	ft_bugsclear(t_bugs **lst)
{
	t_bugs	*tmp;

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

t_bugs	*ft_bugslast(t_bugs *bugs)
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

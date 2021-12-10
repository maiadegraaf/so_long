#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;

	head = NULL;
	if (!lst || !f)
		return (head);
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if (new_list)
			ft_lstadd_back(&head, new_list);
		else
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}

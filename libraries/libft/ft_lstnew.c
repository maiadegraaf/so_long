#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*new_element;

	new_element = (struct s_list *)malloc(sizeof(struct s_list));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->next = NULL;
	return (new_element);
}

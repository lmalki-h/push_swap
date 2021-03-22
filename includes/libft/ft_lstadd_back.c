#include "libft.h"

void	ft_lstadd_back(t_lst **head, t_lst *new)
{
	t_lst	*last;

	if (head && !*head)
	{
		*head = new;
	}
	else if (head && *head)
	{
		last = ft_lstlast(*head);
		last->next = new;
	}
}

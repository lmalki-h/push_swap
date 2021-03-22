#include "libft.h"

t_lst	*ft_lstlast(t_lst *head)
{
	t_lst	*last;

	if (head == NULL)
		return (NULL);
	last = head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

#include "libft.h"

void	free_lst(t_lst *head)
{
	t_lst *tmp;
	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
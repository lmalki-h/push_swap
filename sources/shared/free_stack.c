#include "../../includes/push_swap.h"

void		free_stack(t_stack *head)
{
	t_stack *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
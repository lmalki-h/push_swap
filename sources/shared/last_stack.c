#include "../../includes/push_swap.h"

t_stack *last_stack(t_stack *head)
{
	t_stack *last;

	if (head)
	{
		last = head;
		while (last->next != NULL)
			last = last->next;
		return (last);
	}
	return (NULL);
}

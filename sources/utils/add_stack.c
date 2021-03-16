#include "../../includes/push_swap.h"

void	add_stack(t_stack **head, t_stack *new)
{
	t_stack *last;

	if (head && !*head)
		*head = new;
	else
	{
		last = last_stack(*head);
		last->next = new;
	}
}
#include "../../includes/push_swap.h"

void	add_last(t_stack **head, int n)
{
	t_stack *last;
	t_stack *new;

	new = create_node(n);
	if (!new)
		exit_error(*head);
	if (head && !*head)
		*head = new;
	else
	{
		last = last_stack(*head);
		last->next = new;
	}
}

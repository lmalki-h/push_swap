#include "../../includes/push_swap.h"

/*
**	Moves the first node at the bottom of the stack
*/

void	rotate(t_stack **a)
{
	t_stack *new_head;

	if ( a && *a && (*a)->next)
	{
		new_head = (*a)->next;
		last_stack(*a)->next = *a;
		(*a)->next = NULL;
		(*a) = new_head;
	}
}
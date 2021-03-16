#include "../../includes/push_swap.h"

/*
**	Moves the top element of stack A to the top of stack B
*/

void		push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (a && *a)
	{
		tmp = *a;
		(*a) = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}
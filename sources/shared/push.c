#include "../../includes/push_swap.h"

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
#include "../../includes/push_swap.h"

/*
**	Swap the value of the variable n in the first and second node
*/

void		swap(t_stack **a)
{
	int tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a)->n;
		(*a)->n = (*a)->next->n;
		(*a)->next->n = tmp;
	}
}
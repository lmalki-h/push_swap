#include "../../includes/push_swap.h"

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
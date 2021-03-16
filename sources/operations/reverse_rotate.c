#include "../../includes/push_swap.h"

/*
**	Moves the last element to the top of the stack
*/
void		reverse_rotate(t_stack **a)
{
	t_stack *last;
	t_stack *tmp;

	if (a && *a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *a;
		*a = last;
	}
}
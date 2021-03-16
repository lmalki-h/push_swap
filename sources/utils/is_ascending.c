#include "../../includes/push_swap.h"

/*
** Returns 1 if all numbers stored in A are in ascending order
*/

int		is_ascending(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
#include "../../includes/push_swap.h"

int		get_min(t_stack *a)
{
	int min;
	t_stack *tmp;

	tmp = a;
	min = a->n;
	while (tmp != NULL)
	{
		if (min > tmp->n)
			min = tmp->n;
		tmp = tmp->next;
	}
	return (min);
}
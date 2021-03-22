#include "../../includes/push_swap.h"

int		get_max(t_stack *a)
{
	int max;
	t_stack *tmp;

	tmp = a;
	max = a->n;
	while (tmp != NULL)
	{
		if (max < tmp->n)
			max = tmp->n;
		tmp = tmp->next;
	}
	return (max);
}
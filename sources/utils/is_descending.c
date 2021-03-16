#include "../../includes/push_swap.h"

int		is_descending(t_stack *b)
{
	t_stack *tmp;

	tmp = b;
	while (tmp->next != NULL)
	{
		if (tmp->n < tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
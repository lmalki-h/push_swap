#include "../../includes/push_swap.h"

bool		is_increasing(t_stack *s)
{
	t_stack *tmp;

	tmp = s;
	while (tmp->next != NULL)
	{
		if (tmp->n > tmp->next->n)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
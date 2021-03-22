#include "../../includes/push_swap.h"

size_t	get_index(t_stack *s, int value)
{
	size_t	index;
	t_stack	*tmp;

	tmp = s;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->n == value)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}
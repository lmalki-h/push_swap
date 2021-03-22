#include "../../includes/push_swap.h"

size_t		get_size(t_stack *s)
{
	t_stack *tmp;
	size_t	size;

	size = 0;
	tmp = s;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
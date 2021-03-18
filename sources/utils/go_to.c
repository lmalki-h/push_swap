#include "../../includes/push_swap.h"

t_stack		*go_to(t_stack *s, int index)
{
	t_stack *find;

	find = s;
	while (index)
	{
		find = find->next;
		index--;
	}
	return (find);
}
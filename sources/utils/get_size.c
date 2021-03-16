#include "../../includes/push_swap.h"

int		get_size(t_stack *a)
{
	t_stack *tmp;
	int		count;

	tmp = a;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
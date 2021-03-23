#include "../../includes/push_swap.h"

bool	is_unique(t_stack *head, double n)
{
	t_stack *tmp;
 
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->n == (int)n)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
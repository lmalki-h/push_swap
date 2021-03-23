#include "../../includes/push_swap.h"

t_stack	*create_node(int n)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->n = n;
	return (new);
}

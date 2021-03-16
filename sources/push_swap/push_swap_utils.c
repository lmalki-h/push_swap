#include "../../includes/push_swap.h"
int		find_position(t_stack *s, int n)
{
	int 	position;
	t_stack *tmp;

	tmp = s;
	position = 0;
	while (tmp && tmp->n != n)
	{
		position++;
		tmp = tmp->next;
	}
	return position;
}

int		get_biggest(t_stack *a)
{
	int biggest;
	t_stack *tmp;

	tmp = a;
	biggest = a->n;
	while (tmp != NULL)
	{
		if (biggest < tmp->n)
			biggest = tmp->n;
		tmp = tmp->next;
	}
	return (biggest);
}

int		get_smallest(t_stack *a)
{
	int smallest;
	t_stack *tmp;

	tmp = a;
	smallest = a->n;
	while (tmp != NULL)
	{
		if (smallest > tmp->n)
			smallest = tmp->n;
		tmp = tmp->next;
	}
	return (smallest);
}

#include "../../includes/push_swap.h"

void		sort_small(t_stack **a, size_t size)
{
	int 	top;
	int		pivot;
	t_stack *b;

	top = 0;
	b = NULL;
	pivot = get_pivot(*a, get_max(*a), size);
	// printf("pivot = %i\n", pivot);
	// print_stack(*a, b);
	while (get_size(*a) > 3)
	{
		if ((*a)->n < pivot)
		{
			push(a, &b);
			printf("pb\n");
			// print_stack(*a, b);
		}
		else
		{
			rotate(a);
			printf("ra\n");
			// print_stack(*a, b);
		}
	}
	// print_stack(*a, b);
	sort_three(a);
	// print_stack(*a, b);
	push_back_sorted(&b, a);
}
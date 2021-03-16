#include "../../includes/push_swap.h"

int 	quick_sort_descend(t_stack **b, t_stack **a)
{
	int pivot;

	pivot = last_stack(*b)->n;
	while ((*b)->n != pivot && !is_descending(*b))
	{
		if ((*b)->n < pivot)
		{
			rotate(b);
		}
		else
		{
			swap(b);
		}
			print_stack(*a, *b);

	}
	return 0;

}

int 	quick_sort_ascend(t_stack **a, t_stack **b)
{
	int smallest;

	smallest = get_smallest(*a);
	while ((*a)->n != smallest && get_size(*a) > 3)
	{
		if ((*a)->n > (*a)->next->n)
		{
			rotate(a);
		}
		else
		{
			swap(a);
		}
		print_stack(*a, *b);

	}
	return 0;

}
int		quicksort(t_stack **a, t_stack **b)
{
	int pivot;
	int smallest;
	int biggest;

	smallest = get_smallest(*a);
	biggest = get_biggest(*a);
	pivot = last_stack(*a)->n;
	while ((*a)->next && (*a)->n != pivot)
	{
		if ((*a)->n < pivot)
			push(a, b);
		else
			rotate(a);
		print_stack(*a, *b);
	}
	printf("going into each stack\n");
	sleep(10);
	quick_sort_ascend(a, b);
	quick_sort_descend(b, a);
	return 0;
}
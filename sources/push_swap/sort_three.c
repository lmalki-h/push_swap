#include "../../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int		index_min;
	int		index_max;

	index_max = get_index(*a, get_max(*a));
	index_min = get_index(*a, get_min(*a));
	if (index_max == 0 && index_min == 1)
	{
		rotate(a);
	}
	else if (index_max == 1 && index_min == 2)
	{
		reverse_rotate(a);
	}
	else
	{
		swap(a);
	}
}
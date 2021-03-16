#include "../../includes/push_swap.h"

void	tiny_sort(t_stack **a, char *instructions)
{
	int		smallest;
	int		biggest;

	biggest = get_biggest(*a);
	smallest = get_smallest(*a);
	if ((*a)->n == biggest && (*a)->next->n == smallest)
	{
		rotate(a);
		ft_strlcat(instructions, "ra\n", SIZE);
	}
	else if ((*a)->n != smallest && (*a)->next->n == biggest)
	{
		reverse_rotate(a);
		ft_strlcat(instructions, "rra\n", SIZE);
	}
	else
	{
		swap(a);
		ft_strlcat(instructions, "sa\n", SIZE);
	}
}

// void	medium_sort(t_stack **a, t_stack **b, char *instructions)
// {

// }

// void	huge_sort(t_stack **a, t_stack **b, char *instructions)
// {

// }
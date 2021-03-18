#include "../../includes/push_swap.h"

/*
**	Sort stacks of 2-3 numbers in ascending order 
*/
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

void	medium_sort(t_stack **a, char *instructions)
{
	int 		index;
	t_stack		*unsorted;
	int			size;
	int			sorted;

	sorted = 0;
	size = get_size(*a);
	while (!is_ascending(*a))
	{
		unsorted = go_to(*a, sorted);
		index = find_position(*a, get_biggest(unsorted));
		if (index < (size / 2))
		{
			move_up(a, index, instructions);
		}
		else
		{
			move_down(a, index, instructions);
		}
		sorted++;
	}
}

void	medium_revsort(t_stack **b, char *instructions)
{
	int 		index;
	t_stack		*unsorted;
	int			size;
	int			sorted;

	(void)instructions;
	sorted = 0;
	size = get_size(*b);
	while (!is_descending(*b))
	{
		unsorted = go_to(*b, sorted);
		index = find_position(*b, get_smallest(unsorted));
		if (index < (size / 2))
		{
			move_up(b, index, instructions);
		}
		else
		{
			move_down(b, index, instructions);
		}
		sorted++;
	}
}
void	smart_insert(t_stack **a, t_stack **b, char *instructions)
{
	while ((*a)->n > last_stack(*b)->n)
	{
		rotate(a);
		ft_strlcat(instructions, "ra\n", SIZE);
	}
	while (*b)
	{
		push(b, a);
		ft_strlcat(instructions, "pa\n", SIZE);
	}
}

void	huge_sort(t_stack **a, t_stack **b, char *instructions)
{
	int i;
	int size;
	int pivot;
	
	size = get_size(*a);
	pivot = (get_biggest(*a) + get_smallest(*a)) / 1.5;
	while (!is_ascending(*a))
	{
		i = 0;
		while (i < size) //ON COMPTE LE NOMBRE D'ELEMENT SUPERIEUR A PIVOT DANS LA STACK, SI LE NOMBRE EST TROP PETIT OU TROP GRAND ON MODIFIE LE PIVOT
		{
			if ((*a)->n > pivot)
			{
				push(a, b);
				ft_strlcat(instructions, "pb\n", SIZE);
			}
			else
			{
				reverse_rotate(a);
				ft_strlcat(instructions, "rra\n", SIZE);
			}
			i++;
		}
		if (*b)
		{
			size -= get_size(*b);
			medium_revsort(b, instructions);
			medium_sort(a, instructions);
			smart_insert(a, b, instructions);
			i = 0;
			reverse_rotate(a);
			ft_strlcat(instructions, "rra\n", SIZE);
			pivot /= 1.5;
		}
	}
}
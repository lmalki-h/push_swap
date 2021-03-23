#include "../../includes/push_swap.h"

void	move_to_top(t_stack **s, size_t index)
{
	size_t size;

	size = get_size(*s);
	if (index < size / 2)
	{
		while (index--)
		{
			rotate(s);
			printf("rb\n");
		}
	}
	else
	{
		while (index++ < size)
		{
			reverse_rotate(s);
			printf("rrb\n");
		}
	}
}
void		move_top(t_stack **a, size_t unsorted, size_t size)
{
	size_t i;

	i = 0;
	if (unsorted < size / 2)
	{
		while (i++ < unsorted)
		{
			reverse_rotate(a);
			printf("rra\n");
		}
	}
	else
	{
		while (unsorted + i++ < size)
		{
			rotate(a);
			printf("ra\n");
		}
	}
}

static void	divide(t_stack **src, t_stack **dst, int size, int pivot)
{
	while (size--)
	{
		if ((*src)->n >= pivot)
		{
			push(src, dst);
			printf("pb\n");
		}
		else
		{
			rotate(src);
			printf("ra\n");
		}
	}
}

void	empty_b(t_stack **b, t_stack **a)
{
	while (*b)
	{
		move_to_top(b, get_index(*b, get_max(*b)));
		push(b, a);
		printf("pa\n");
	}
}

void	sort_big(t_stack **a, size_t size)
{
	size_t	unsorted;
	t_stack *b;

	b = NULL;
	unsorted = size;
	while (unsorted)
	{
		move_top(a, unsorted, size);
		divide(a, &b, unsorted, get_pivot(*a, unsorted));
		unsorted -= get_size(b);
		empty_b(&b, a);
	}
}
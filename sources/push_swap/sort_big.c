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

void		down_to_pivot(t_stack *s, int *limit, size_t size)
{
	t_stack *tmp;
	int		pivot;

	tmp = s;
	pivot = get_min(s);
	while (size--)
	{
		if (tmp->n > pivot && tmp->n < *limit)
			pivot = tmp->n;
		tmp = tmp->next;
	}
	*limit = pivot;
}

int		get_divider(size_t size)
{
	if (size > CENT)
		return (CINQUANTE);
	else if (size > CINQUANTE)
		return (VINGTCINQ);
	else if (size < 6)
		return (size / 2);
	else
		return (1);
}

int		get_pivot(t_stack *s, size_t size)
{
	int			divider;
	int			pivot;

	divider = get_divider(size);
	if (divider == 1)
		return (get_min(s));
	pivot = get_max(s);
	while (divider--)
		down_to_pivot(s, &pivot, size);
	return (pivot);
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
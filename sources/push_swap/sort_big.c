#include "../../includes/push_swap.h"

static void	move_to_top(t_stack **s, size_t index)
{
	size_t size;

	size = get_size(*s);
	//if size == 3 sort three
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

static void	divide(t_stack **src, t_stack **dst, int size,  int pivot)
{
	while (size--) //get_size(*dst) < DEFAULT_SIZE &&
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

static void	push_back_sorted(t_stack **src, t_stack **dst)
{
	size_t	index;

	while (*src)
	{
		index = get_index(*src, get_max(*src));
		move_to_top(src, index);
		push(src, dst);
		printf("pa\n");
	}
}

/*
**	Returns for the next biggest number (after max) 
**	in the SIZE first element of the stack
*/

static int		get_next_value(t_stack *s, int max, int size)
{
	int 	i;
	int		pivot;
	t_stack	*tmp;

	i = 0;
	tmp = s;
	pivot = get_min(s);
	while (i < size)
	{
		if (tmp->n > pivot && tmp->n < max)
			pivot = tmp->n;
		tmp = tmp->next;
		i++;
	}
	return (pivot);
}

static int		get_pivot(t_stack *s, int max, size_t size)
{
	size_t i;
	int pivot;
	
	i = 0;
	if (size < DEFAULT_SIZE)
		return (get_min(s));
	while (i < DEFAULT_SIZE)
	{
		pivot = get_next_value(s, max, size);
		max = pivot;
		i++;
	}
	return (pivot);
}

void	sort_big(t_stack **a, size_t size)
{
	size_t 	sorted;
	size_t	unsorted;
	int 	pivot;
	int		max;
	t_stack *b;

	b = NULL;
	sorted = 0;
	unsorted = size;
	max = get_max(*a);
	while (sorted < size)
	{
		if (sorted < size / 2)
		{
			while (sorted--)
			{
				rotate(a);
				printf("ra\n");
			}
		}
		else
		{
			size_t i = 0;
			while (i < unsorted)
			{
				reverse_rotate(a);
				printf("rra\n");
				i++;
			}
		}
		pivot = get_pivot(*a, max, unsorted);
		max = pivot;
		divide(a, &b, unsorted, pivot);
		unsorted -= get_size(b);
		sorted = size - unsorted;
		//TODO: before push back bring sorted to the top
		push_back_sorted(&b, a);
	}
}
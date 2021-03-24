/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:37:40 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/24 08:47:57 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			move_to_top(t_stack **s, size_t index)
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

void			move_top(t_stack **a, size_t unsorted, size_t size)
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

static void		divide(t_stack **a, t_stack **b, size_t unsorted, size_t size_sub_stack)
{
	int pivot;

	pivot = get_pivot(*a, unsorted);
	while (unsorted-- && get_size(*b) < size_sub_stack)
	{
		if ((*a)->n >= pivot)
		{
			push(a, b);
			printf("pb\n");
		}
		else
		{
			rotate(a);
			printf("ra\n");
		}
	}
}

void			empty_b(t_stack **b, t_stack **a)
{
	while (*b)
	{
		move_to_top(b, get_index(*b, get_max(*b)));
		push(b, a);
		printf("pa\n");
	}
}

void			sort_big(t_stack **a, size_t size)
{
	size_t 	size_sub_stack;
	size_t	nb_of_sub_stacks;

	size_t	unsorted;
	t_stack *b;

	b = NULL;
	size_sub_stack = get_divider(size);
	nb_of_sub_stacks = size / size_sub_stack;
	unsorted = size;
	while (unsorted && nb_of_sub_stacks--)
	{
		//WITHIN THE LOOP SORTS ONE SUB_STACK
		move_top(a, unsorted, size);
		divide(a, &b, unsorted, size_sub_stack);
		unsorted -= get_size(b);
		empty_b(&b, a);
	}
}

// int			get_pivot(t_stack **a, size_t size_b, size_t size_a)
// {
// 	t_stack *tmp;
// 	size_t	i;
// 	int 	pivot;
// 	int		limit;

// 	limit = get_max(*a);
// 	while (size_b--)
// 	{
// 		i = 0;
// 		tmp = *a;
// 		pivot = tmp->n;
// 		while (i++ < size_a)
// 		{
// 			if (tmp->n > pivot && pivot < limit) 
// 				pivot = tmp->n;
// 			tmp = tmp->next;
// 		}
// 		limit = pivot;
// 	}
// 	return (pivot);
// }
// void		push_pre_sorted(t_stack **a, t_stack **b, size_t size)
// {
// 	int 	pivot;

// 	pivot = get_pivot(a, size_sub_stack, size); 
// }
// void		sort_big(t_stack **a, size_t size)
// {
// 	size_t		size_sub_stack;
// 	size_t		nb_of_splits;

// 	while (nb_of_splits--)
// 	{
// 		//push_pre_sorted
// 		//push_back_sorted
// 	}
// }
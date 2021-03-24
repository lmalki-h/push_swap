/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:37:40 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/24 12:27:55 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			move_top(t_stack **s, size_t index)
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

void			move_sorted_down(t_stack **a, size_t unsorted)
{
	size_t size;

	size = get_size(*a);
	if (unsorted < size / 2)
	{
		while (unsorted--)
		{
			reverse_rotate(a);
			printf("rra\n");
		}
	}
	else
	{
		while (unsorted++ < size)
		{
			rotate(a);
			printf("ra\n");
		}
	}
}

static void		push_some_unsorted_to_b(t_stack **a, t_stack **b,
					size_t unsorted, size_t divider)
{
	int pivot;

	pivot = get_pivot(*a, unsorted, divider);
	while (unsorted--)
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

void			push_back_sorted(t_stack **dst, t_stack **src)
{
	while (*src)
	{
		move_top(src, get_index(*src, get_max(*src)));
		push(src, dst);
		printf("pa\n");
	}
}

void			sort_big(t_stack **a, size_t size)
{
	int		divider;
	size_t	unsorted;
	t_stack *b;

	b = NULL;
	divider = get_divider(size);
	unsorted = size;
	while (unsorted)
	{
		move_sorted_down(a, unsorted);
		push_some_unsorted_to_b(a, &b, unsorted, divider);
		unsorted -= get_size(b);
		push_back_sorted(a, &b);
	}
}

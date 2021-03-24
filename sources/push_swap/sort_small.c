/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:01:38 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/24 10:58:24 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		sort_small(t_stack **a, size_t size)
{
	int		divider;
	t_stack *b;
	int		pivot;

	b = NULL;
	divider = get_divider(size);
	pivot = get_pivot(*a, size, divider);
	while (get_size(*a) > 3)
	{
		if ((*a)->n < pivot)
		{
			push(a, &b);
			printf("pb\n");
		}
		else
		{
			rotate(a);
			printf("ra\n");
		}
	}
	if (get_size(*a) < 4)
		sort_three(a);
	push_back_sorted(a, &b);
}

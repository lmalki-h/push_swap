/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:01:38 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 21:01:48 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		sort_small(t_stack **a, size_t size)
{
	int		top;
	int		pivot;
	t_stack *b;

	top = 0;
	b = NULL;
	pivot = get_pivot(*a, size);
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
	sort_three(a);
	empty_b(&b, a);
}

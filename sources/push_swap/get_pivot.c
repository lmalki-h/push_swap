/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:24:55 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 21:36:59 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	down_to_pivot(t_stack *s, int *limit, size_t size)
{
	t_stack	*tmp;
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

static int	get_divider(size_t size)
{
	if (size > HUNDRED)
		return (FIFTY);
	else if (size > FIFTY)
		return (TWENTYFIVE);
	else if (size < 6)
		return (size / 2);
	else
		return (1);
}

int			get_pivot(t_stack *s, size_t size)
{
	int		divider;
	int		pivot;

	divider = get_divider(size);
	if (divider == 1)
		return (get_min(s));
	pivot = get_max(s);
	while (divider--)
		down_to_pivot(s, &pivot, size);
	return (pivot);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:24:55 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/24 11:19:24 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//TODO: Ameliorer ces functions
static void	down_to_pivot(t_stack *s, int *limit, size_t unsorted)
{
	t_stack	*tmp;
	int		pivot;

	tmp = s;
	pivot = get_min(s);
	while (unsorted--)
	{
		if (tmp->n > pivot && tmp->n < *limit)
			pivot = tmp->n;
		tmp = tmp->next;
	}
	*limit = pivot;
}

int			get_pivot(t_stack *s, size_t unsorted, size_t divider)
{
	int		pivot;

	pivot = get_max(s);
	while (divider--)
		down_to_pivot(s, &pivot, unsorted);
	return (pivot);
}

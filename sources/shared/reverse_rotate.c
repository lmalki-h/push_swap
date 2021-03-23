/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:45:21 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:45:29 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		reverse_rotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*before_last;

	if (a && *a && (*a)->next)
	{
		before_last = *a;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *a;
		*a = last;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:45:53 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:46:07 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*new_head;

	if (a && *a && (*a)->next)
	{
		new_head = (*a)->next;
		last_stack(*a)->next = *a;
		(*a)->next = NULL;
		(*a) = new_head;
	}
}

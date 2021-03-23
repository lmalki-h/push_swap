/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:36:36 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:36:37 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_last(t_stack **head, int n)
{
	t_stack *last;
	t_stack *new;

	new = create_node(n);
	if (!new)
		exit_error(*head);
	if (head && !*head)
		*head = new;
	else
	{
		last = last_stack(*head);
		last->next = new;
	}
}

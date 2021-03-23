/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:42:06 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:42:17 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*last_stack(t_stack *head)
{
	t_stack	*last;

	if (head)
	{
		last = head;
		while (last->next != NULL)
			last = last->next;
		return (last);
	}
	return (NULL);
}

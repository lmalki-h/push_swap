/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_decreasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:40:24 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:40:31 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool		is_decreasing(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (tmp->next != NULL)
	{
		if (tmp->n < tmp->next->n)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:58:15 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:58:24 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_max(t_stack *a)
{
	int		max;
	t_stack *tmp;

	tmp = a;
	max = a->n;
	while (tmp != NULL)
	{
		if (max < tmp->n)
			max = tmp->n;
		tmp = tmp->next;
	}
	return (max);
}

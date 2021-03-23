/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:58:52 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:58:57 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_min(t_stack *a)
{
	int		min;
	t_stack *tmp;

	tmp = a;
	min = a->n;
	while (tmp != NULL)
	{
		if (min > tmp->n)
			min = tmp->n;
		tmp = tmp->next;
	}
	return (min);
}

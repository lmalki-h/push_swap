/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:57:35 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:57:42 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	get_index(t_stack *s, int value)
{
	size_t	index;
	t_stack	*tmp;

	tmp = s;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->n == value)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

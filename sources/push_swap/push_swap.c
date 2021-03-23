/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:59:15 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:59:16 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_stack *a)
{
	size_t size;

	size = get_size(a);
	if (!is_increasing(a))
	{
		if (size < 4)
		{
			sort_three(&a);
		}
		else if (size < 6)
		{
			sort_small(&a, size);
		}
		else
		{
			sort_big(&a, size);
		}
	}
	free_stack(a);
}

int		main(int ac, char **av)
{
	t_stack *a;

	a = NULL;
	if (ac > 1)
	{
		parse_arguments(&a, &av[1]);
		if (!a)
			exit_error(NULL);
		push_swap(a);
	}
	return (0);
}

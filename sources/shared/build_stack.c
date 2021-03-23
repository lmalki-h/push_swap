/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:37:43 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:37:53 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	parse_arguments(t_stack **head, char **av)
{
	double	n;
	char	*s;

	while (*av != NULL)
	{
		s = *av;
		while (*s != '\0')
		{
			while (*s == ' ')
				s++;
			if (*s == '-' || *s == '+' || ft_isdigit(*s))
			{
				n = atod(&s);
				if (!is_integer(n) || !is_unique(*head, n))
				{
					exit_error(*head);
				}
				add_last(head, (int)n);
			}
			else if (*s != ' ')
				exit_error(*head);
		}
		av++;
	}
}

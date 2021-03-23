/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:38:35 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:38:55 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		exit_error(t_stack *head)
{
	if (head)
		free_stack(head);
	write(STDERR_FILENO, "Error\n", 6);
	exit(-1);
}

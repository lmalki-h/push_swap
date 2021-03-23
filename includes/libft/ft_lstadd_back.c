/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:18:13 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:18:15 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_lst **head, t_lst *new)
{
	t_lst	*last;

	if (head && !*head)
	{
		*head = new;
	}
	else if (head && *head)
	{
		last = ft_lstlast(*head);
		last->next = new;
	}
}

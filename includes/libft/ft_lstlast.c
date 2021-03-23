/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:18:37 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:18:37 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstlast(t_lst *head)
{
	t_lst	*last;

	if (head == NULL)
		return (NULL);
	last = head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

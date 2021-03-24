/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_divider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:52:18 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/24 11:52:20 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		get_divider(size_t size)
{
	if (size > HUNDRED)
		return (FIFTY);
	else if (size > FIFTY)
		return (TWENTYFIVE);
	else
		return (size / 2);
}

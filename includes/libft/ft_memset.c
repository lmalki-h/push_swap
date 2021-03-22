/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:32:09 by lmalki-h          #+#    #+#             */
/*   Updated: 2020/02/04 10:59:19 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	data;
	unsigned char	*s;
	size_t			i;

	data = (unsigned char)c;
	s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = data;
		i++;
	}
	return (s);
}

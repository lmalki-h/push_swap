/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:19:48 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/03/23 20:20:02 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcat(char *dst, char *src, int len)
{
	int size;
	int	i;

	i = 0;
	size = ft_strlen(dst);
	while (src[i] && size + i < len)
	{
		dst[size] = src[i];
		i++;
	}
}

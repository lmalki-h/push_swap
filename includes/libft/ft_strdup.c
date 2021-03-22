/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:03:09 by lmalki-h          #+#    #+#             */
/*   Updated: 2019/11/21 17:21:24 by lmalki-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;
	int		i;

	len = ft_strlen(s1);
	if ((copy = (char *)ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	copy[len] = '\0';
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmalki-h <lmalki-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:24:44 by lmalki-h          #+#    #+#             */
/*   Updated: 2021/01/18 15:58:53 by mrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_add(char *s, char c)
{
	char	*new;
	int		len_new;
	int		i;

	i = 0;
	len_new = ft_strlen(s) + 2;
	new = (char *)ft_calloc(sizeof(char), len_new);
	if (new == NULL)
	{
		if (s)
			free(s);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	free(s);
	return (new);
}

int		get_next_line(int fd, char **line)
{
	char		*s;
	char		buffer[1];
	int			ret;

	if (!line || (s = (char *)ft_calloc(sizeof(char), 1)) == NULL)
		return (-1);
	buffer[0] = '\0';
	while ((ret = read(fd, buffer, 1)) > -1)
	{
		if ((ret == 0 && ft_strlen(s) == 0) || buffer[0] == '\n')
			break ;
		if (ret > 0)
			s = str_add(s, buffer[0]);
		else
			write(1, "  \b\b", 4);
	}
	if (buffer[0] == '\n' || ft_strcmp(s, "") != 0)
		*line = ft_strdup(s);
	else
		*line = NULL;
	if (s)
		free(s);
	return (ret);
}

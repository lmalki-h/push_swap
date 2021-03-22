#include "libft.h"
# include <stdio.h>
char	*update(char *s, char *add)
{
	char *new;
	size_t len_new;

	len_new = ft_strlen(s) + ft_strlen(add);
	new = (char *)ft_calloc(sizeof(char), len_new + 1);
	if (!new)
		return (NULL);
	ft_strlcat(new, s, len_new + 1);
	ft_strlcat(new, add, len_new + 1);
	free(s);
	return new;
}
int		get_next_line(int fd, char **line)
{
	static	char *s = NULL;
	char	*newline;
	char	buf[BUF_SIZE + 1];
	int		ret;

	if (fd < 0 || !line)
	{
		return (-1);
	}
	if (!s)
		s = strdup("");
	while ((ret = read(fd, buf, BUF_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		s = update(s, buf);
		if ((newline = ft_strchr(s, '\n')) != NULL)
		{
			*line = ft_substr(s, 0, newline - s);
			s = ft_strdup(newline + 1);
			return 1;
		}
		else if (ret == 0)
		{
			if (*s)
			{
				*line = ft_strdup(s);
				free(s);
			}
			else
				*line = NULL;
			return 0;		}
	}
	free(s);
	return -1;
}
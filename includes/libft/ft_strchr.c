# include "libft.h"

char	*ft_strchr(char *s, char delim)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delim)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
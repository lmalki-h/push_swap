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


#include "libft.h"

double		atod(char **s)
{
	double 	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*s[0] == '-' || *s[0] == '+')
	{
		if (*s[0] == '-')
			sign = -1;
		(*s)++;
	}
	while (ft_isdigit((*s)[0]))
	{
		num *= 10;
		num += (int)((*s)[0]) - '0';
		(*s)++;
	}
	return (num * (double)sign);
}
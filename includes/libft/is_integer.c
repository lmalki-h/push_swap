#include "libft.h"

bool	is_integer(double n)
{
	if (n >= INT_MIN && n <= INT_MAX)
		return (true);
	return (false);
}

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
#include "../../includes/push_swap.h"

void		exit_error(t_stack *head)
{
	if (head)
		free_stack(head);
	write(STDERR_FILENO, "Error\n", 6);
	exit (-1);
}